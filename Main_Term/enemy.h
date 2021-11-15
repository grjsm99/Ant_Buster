#pragma once
#include "transform.h"
#include "model_3d.h"

class Enemy {
protected:
	Model3D* image;

	Transform trans;
	float hp, hpMax;
	float speed;

public:
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

class Ant : public Enemy {

public:
	void Draw(GLuint _shaderID) {
		// modelTransform�� ���Ͽ� ��Ƽ������ ���� ����

		// ���� ��ο�
		image->Draw();
	}
};




