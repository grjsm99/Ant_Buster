#pragma once
#include <gl/glew.h> 
#include <gl/freeglut.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "camera.h"
#include "Sphere.h"


class State {

public:
	GLvoid(*Reshapeptr)(int w, int h);
	GLvoid(*drawSceneptr)();
	GLvoid(*sKeyboardptr)(int key, int x, int y);
	GLvoid(*Keyboardptr)(unsigned char key, int x, int y);
	GLvoid(*Mouseptr)(int button, int state, int x, int y);
	GLvoid(*Motionptr)(int x, int y);
};

class startState : public State {

public:
	static std::vector<Transform*> objlist;
	static Camera cam;

	startState() {
		Reshapeptr = Reshape;
		drawSceneptr = drawScene;
		sKeyboardptr = sKeyboard;
		Keyboardptr = Keyboard;
		Mouseptr = Mouse;
		Motionptr = Motion;

	};
	static GLvoid Reshape(int w, int h);
	static GLvoid drawScene();
	static GLvoid sKeyboard(int key, int x, int y);
	static GLvoid Keyboard(unsigned char key, int x, int y);
	static GLvoid Mouse(int button, int state, int x, int y);
	static GLvoid Motion(int x, int y);
};

class mainState : public State {

public:
	static std::vector<Transform*> objlist;
	static Camera cam;

	mainState() {
		Reshapeptr = Reshape;
		drawSceneptr = drawScene;
		sKeyboardptr = sKeyboard;
		Keyboardptr = Keyboard;
		Mouseptr = Mouse;
		Motionptr = Motion;
		Transform* t = new Sphere(1,0,0,1);
		objlist.push_back(t);
		Transform* m = new Sphere(-1, 0, 0,1);
		objlist.push_back(m);
	};
	static GLvoid Reshape(int w, int h);
	static GLvoid drawScene();
	static GLvoid sKeyboard(int key, int x, int y);
	static GLvoid Keyboard(unsigned char key, int x, int y);
	static GLvoid Mouse(int button, int state, int x, int y);
	static GLvoid Motion(int x, int y);


};