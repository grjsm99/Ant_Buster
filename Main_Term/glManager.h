#pragma once
#include <gl/glew.h> 
#include <gl/freeglut.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <iostream>

#include "model_3d.h"
#include "model_maker.h"
class GLManager {

	std::vector<GLuint>* shPoint;
	int width;
	int height;

public:
	GLManager(int, int, int, char**);

	static GLvoid Reshape(int w, int h);
	static GLvoid drawScene();
	static GLvoid sKeyboard(int key, int x, int y);
	static GLvoid Keyboard(unsigned char key, int x, int y);
	static GLvoid Mouse(int button, int state, int x, int y);
	static GLvoid Motion(int x, int y);

	void mainLoop();
};