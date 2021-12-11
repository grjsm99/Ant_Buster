#pragma once
#include "model_3d.h"
#include "global_var.h"
//#include "mainState.h"

class AntNest : public Object {
	Model3D* myModel = &GloVar::model_antNest;
	Texture* texture = &GloVar::AntNestTexture;
	int cooldown = 120; // 프레임 단위
	int stage = 1;
	int antSpawnCount = 0;
	int cool = 0;
public:
	AntNest();

	void Draw();

	void Update();

	void Reset();

};