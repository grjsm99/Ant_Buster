#pragma once
#include <gl/glew.h> 
#include <gl/freeglut.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>

class State {
public:	
	GLvoid (*Reshapeptr)(int w, int h);
	GLvoid (*drawSceneptr)();
	GLvoid (*sKeyboardptr)(int key, int x, int y);
	GLvoid (*Keyboardptr)(unsigned char key, int x, int y);
	GLvoid (*Mouseptr)(int button, int state, int x, int y);
	GLvoid (*Motionptr)(int x, int y);

	virtual void SetCallbackFunc() = 0;

};