#pragma once
#include <gl/glew.h> 
#include <gl/freeglut.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>

class Shader {
	std::vector<GLuint> shaderID;

public:
	Shader() {};
	void InitShader(const char* vsName, const char* fsName);
	GLuint rtsh(int i) {
		return shaderID[i];
	}
};