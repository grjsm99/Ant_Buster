#pragma once
#include "model_3d.h"
#include "global_var.h"

class Ant : public Object {
	Model3D* myModel = &GloVar::model_ant;
	Texture* texture = &GloVar::AntTexture;
	float hp = 200;
	float speed = 0.05f;
	float moveDist = 0;
	bool isplusz = true;
	int bounty;

public:
	Ant();

	void Draw();
	bool Update();
	void Attacked(float _dmg);
};