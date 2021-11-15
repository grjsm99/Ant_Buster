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
#include "shader.h"

class ModelMaker {
private:
	int num_Triangle;
	int minX, maxX, minY, maxY, minZ, maxZ;

	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;

	std::vector< glm::vec3 > temp_vertices;
	std::vector< glm::vec3 > temp_normals;
	std::vector< glm::vec2 > temp_uvs;

	std::vector< glm::vec3 > out_vertex;
	std::vector< glm::vec3 > out_normal;
	std::vector< glm::vec2 > out_uv;

public:
	~ModelMaker();

	void LoadObj(const char* filename);

	Model3D MakeModel3D(GLuint shadeNname, std::string posName, std::string normalName );

};



