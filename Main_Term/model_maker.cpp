#define _CRT_SECURE_NO_WARNINGS
#include "model_maker.h"

//모델메이커
ModelMaker::~ModelMaker() {
	temp_vertices.shrink_to_fit();
	temp_uvs.shrink_to_fit();
	temp_normals.shrink_to_fit();

	vertexIndices.shrink_to_fit();
	uvIndices.shrink_to_fit();
	normalIndices.shrink_to_fit();

	out_vertex.shrink_to_fit();
	out_normal.shrink_to_fit();
	out_uv.shrink_to_fit();
}

void ModelMaker::LoadObj(const char* filename) {
	//기존에 있던 벡터 초기화
	temp_vertices.clear();
	temp_uvs.clear();
	temp_normals.clear();

	vertexIndices.clear();
	uvIndices.clear();
	normalIndices.clear();

	out_vertex.clear();
	out_normal.clear();
	out_uv.clear();


	//
	minX = 0.0; minY = 0.0; minZ = 0.0;
	maxX = 0.0; maxY = 0.0; maxZ = 0.0;

	FILE* objFile;

	fopen_s(&objFile, filename, "rb");

	if (objFile == NULL) {
		printf("파일을 열수 없습니다!\n");
		return;
	}
	while (1) {
		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(objFile, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.
		if (strcmp(lineHeader, "v") == 0) {
			glm::vec3 vertex;
			fscanf_s(objFile, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);

			if (vertex.x < minX) minX = vertex.x;
			if (vertex.y < minY) minY = vertex.y;
			if (vertex.z < minZ) minZ = vertex.z;
			if (vertex.x > maxX) maxX = vertex.x;
			if (vertex.y > maxY) maxY = vertex.y;
			if (vertex.z > maxZ) maxZ = vertex.z;

			temp_vertices.push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0) {
			glm::vec2 uv;
			fscanf_s(objFile, "%f %f\n", &uv.x, &uv.y);
			temp_uvs.push_back(uv);
		}
		else if (strcmp(lineHeader, "vn") == 0) {
			glm::vec3 normal;
			fscanf_s(objFile, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			temp_normals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f") == 0) {
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf_s(objFile, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if (matches != 9) {
				printf("File can't be read by our simple parser : ( Try exporting with other options\n");
				return;
			}
			// 인덱스 번호가 0번부터 시작되도록 -1을 해줌
			vertexIndices.push_back(vertexIndex[0] - 1);
			vertexIndices.push_back(vertexIndex[1] - 1);
			vertexIndices.push_back(vertexIndex[2] - 1);
			uvIndices.push_back(uvIndex[0] - 1);
			uvIndices.push_back(uvIndex[1] - 1);
			uvIndices.push_back(uvIndex[2] - 1);
			normalIndices.push_back(normalIndex[0] - 1);
			normalIndices.push_back(normalIndex[1] - 1);
			normalIndices.push_back(normalIndex[2] - 1);
		}
	}

	// 모델이 [-0.5, 0.5], [-0.5, 0.5], [-0.5, 0.5] 크기안에 맞도록 조정하기
	glm::mat4 standard_transform(1.0f);
	float maxSide = std::max({ maxX - minX, maxY - minY, maxZ - minZ });
	standard_transform = glm::scale(standard_transform, glm::vec3( 1 / maxSide, 1 / maxSide, 1 / maxSide) );
	standard_transform = glm::translate(standard_transform, glm::vec3(-(maxX + minX) / 2, -(maxY + minY) / 2, -(maxZ + minZ) / 2));

	for (unsigned int i = 0; i < temp_vertices.size(); ++i) {
		temp_vertices[i] = standard_transform * glm::vec4(temp_vertices[i], 1.0f);
	}


	// initBuffer 할 버텍스 만들기
	for (unsigned int i = 0; i < vertexIndices.size(); i++) {
		unsigned int vertexIndex = vertexIndices[i];
		glm::vec3 vertex = temp_vertices[vertexIndex];
		out_vertex.push_back(vertex);
	}
	for (unsigned int i = 0; i < uvIndices.size(); i++) {
		unsigned int uvIndex = uvIndices[i];
		glm::vec2 vertex = temp_uvs[uvIndex];
		out_uv.push_back(vertex);
	}
	for (unsigned int i = 0; i < normalIndices.size(); i++) {
		unsigned int normalIndex = normalIndices[i];
		glm::vec3 vertex = temp_normals[normalIndex];
		out_normal.push_back(vertex);
	}

	num_Triangle = out_vertex.size();
	maxX = (maxX - (minX + maxX) / 2) / maxSide;
	minX = -maxX;
	maxY = (maxY - (minY + maxY) / 2) / maxSide;
	minY = -maxY;
	maxZ = (maxZ - (minZ + maxY) / 2) / maxSide;
	minZ = -maxZ;

	//필요없는 벡터 삭제
	temp_vertices.shrink_to_fit();
	temp_uvs.shrink_to_fit();
	temp_normals.shrink_to_fit();

	vertexIndices.shrink_to_fit();
	uvIndices.shrink_to_fit();
	normalIndices.shrink_to_fit();

}

Model3D ModelMaker::MakeModel3D(GLuint shaderName, std::string posName, std::string normalName) {
	Model3D model;

	GLuint VBO_position, VBO_normal;
	glGenVertexArrays(1, model.GetPVAO()); //--- VAO 를 지정하고 할당하기
	glGenBuffers(1, &VBO_position);
	glGenBuffers(1, &VBO_normal);

	glBindVertexArray(model.GetVAO()); //--- VAO를 바인드하기

	glBindBuffer(GL_ARRAY_BUFFER, VBO_position);
	glBufferData(GL_ARRAY_BUFFER, out_vertex.size() * sizeof(glm::vec3), &out_vertex[0], GL_STATIC_DRAW);
	GLint pAttribute = glGetAttribLocation(shaderName, posName.c_str());
	glVertexAttribPointer(pAttribute, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(pAttribute);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_normal);
	glBufferData(GL_ARRAY_BUFFER, out_normal.size() * sizeof(glm::vec3), &out_normal[0], GL_STATIC_DRAW);
	GLint nAttribute = glGetAttribLocation(shaderName, normalName.c_str());
	glVertexAttribPointer(nAttribute, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(nAttribute);


	model.SetNumTriangle(num_Triangle);
	model.maxX = maxX;
	model.minX = minX;
	model.maxY = maxY;
	model.minY = minY;
	model.maxZ = maxZ;
	model.minZ = minZ;
	

	return model;
}
