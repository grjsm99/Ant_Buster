#pragma once
#include "global_var.h"

#include "state.h"
#include "mainState.h"

#include "model_3d.h"
#include "model_maker.h"
#include "glManager.h"

class startState : public State {
	static GLvoid Reshape(int w, int h);
	static GLvoid drawScene();
	static GLvoid sKeyboard(int key, int x, int y);
	static GLvoid Keyboard(unsigned char key, int x, int y);
	static GLvoid Mouse(int button, int state, int x, int y);
	static GLvoid Motion(int x, int y);
	static GLvoid Update(int value);

public:
	//생성자
	startState() {
		SetCallbackFunc();
	};

	//자신의 함수 연결하기
	void SetCallbackFunc();
	
};