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
#include "tower.h"
#include "attack.h"

class mainState : public State {
	//�ʼ� �Լ���
	static GLvoid Reshape(int w, int h);
	static GLvoid drawScene();
	static GLvoid sKeyboard(int key, int x, int y);
	static GLvoid Keyboard(unsigned char key, int x, int y);
	static GLvoid Mouse(int button, int state, int x, int y);
	static GLvoid Motion(int x, int y);
	static GLvoid Update(int value);

	//����
	static Camera camera;
	static Light sun;
	static Plain plain;
	static AntNest antNest;
	

public:
	//public ����
	static std::vector<Ant*> ants;
	static std::vector<Tower*> towers;
	static std::vector<Attack*> attacks;
	static glm::vec3 attLights[200];
	//������
	mainState() {
		SetCallbackFunc();

		Tower* t = new Tower(5, 5);
		towers.push_back(t);
		t = new Tower(5, 6);
		towers.push_back(t);
		t = new Tower(5, 7);
		towers.push_back(t);
		/*for (int i = 0; i < 10; i++) {
			for (int j = 2; j < 10; j++) {
				Tower* t = new Tower(j, i);
				towers.push_back(t);
			}
		}
		*/
	};

	//�ڽ��� �Լ� �����ϱ�
	void SetCallbackFunc();

};
