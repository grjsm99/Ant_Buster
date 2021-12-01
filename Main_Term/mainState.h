#pragma once
#include <vector>

#include "global_var.h"

#include "state.h"
#include "model_3d.h"
#include "model_maker.h"
#include "glManager.h"
#include "light.h"
#include "plain.h"
#include "ant_nest.h"
#include "ant.h"

class mainState : public State {
	//필수 합수들
	static GLvoid Reshape(int w, int h);
	static GLvoid drawScene();
	static GLvoid sKeyboard(int key, int x, int y);
	static GLvoid Keyboard(unsigned char key, int x, int y);
	static GLvoid Mouse(int button, int state, int x, int y);
	static GLvoid Motion(int x, int y);
	static GLvoid Update(int value);

	//변수
	static Camera camera;
	static Light sun;
	static Plain plain;
	static AntNest antNest;
	

public:
	//public 변수
	static std::vector<Ant*> ants;

	//생성자
	mainState() {
		SetCallbackFunc();
	};

	//자신의 함수 연결하기
	void SetCallbackFunc();

};
