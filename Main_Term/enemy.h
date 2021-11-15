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
		// modelTransform을 구하여 유티폼으로 값을 전달

		// 그후 드로우
		image->Draw();
	}
};




