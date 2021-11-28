#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <string>

#include <gl/glew.h>
#include <gl/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "model_3d.h"

class ModelMaker {
private:
	int num_Triangle;
	float minX, maxX, minY, maxY, minZ, maxZ;
	
	glm::vec3 rotation = glm::vec3(0, 0, 0);
	glm::vec3 size = glm::vec3(1, 1, 1);
	glm::vec3 location = glm::vec3(0, 0, 0);

	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;

	std::vector< glm::vec3 > temp_vertices;
	std::vector< glm::vec3 > temp_normals;
	std::vector< glm::vec2 > temp_uvs;

	std::vector< glm::vec3 > out_vertex;
	std::vector< glm::vec3 > out_normal;
	std::vector< glm::vec2 > out_uv;

public:
	~ModelMaker();

	void SetRotation(glm::vec3 _rotation);
	void SetSize(glm::vec3 _size);
	void SetLocation(glm::vec3 _location);
	void ResetRotation();
	void ResetSize();
	void ResetLocation();

	void SetTransform(glm::vec3 _rotation, glm::vec3 _size, glm::vec3 _location);
	void ResetTransform();

	void LoadObj(const char* filename);

	Model3D MakeModel3D(GLuint _shaderID, std::string posName, std::string normalName );
	Model3D MakeModel3D(GLuint _shaderID, std::string posName, std::string normalName, std::string textureName);
};
