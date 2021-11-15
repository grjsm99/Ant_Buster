#pragma once
#include <gl/glew.h> 
#include <gl/freeglut.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>
#include "camera.h"

class Shader {

	GLuint shaderID;

public:
	Shader();
	void InitShader(const char* vsName, const char* fsName);
	GLuint rtsh() {
		return shaderID;
	}
};