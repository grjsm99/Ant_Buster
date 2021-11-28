#pragma once
#include "global_var.h"

#include "state.h"

#include "model_3d.h"
#include "model_maker.h"
#include "glManager.h"

class mainState : public State {
	//�ʼ� �ռ���
	static GLvoid Reshape(int w, int h);
	static GLvoid drawScene();
	static GLvoid sKeyboard(int key, int x, int y);
	static GLvoid Keyboard(unsigned char key, int x, int y);
	static GLvoid Mouse(int button, int state, int x, int y);
	static GLvoid Motion(int x, int y);

	//����
	static Camera camera;

public:
	//������
	mainState() {
		SetCallbackFunc();
	};

	//�ڽ��� �Լ� �����ϱ�
	void SetCallbackFunc();

};
