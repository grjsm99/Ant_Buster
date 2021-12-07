#pragma once
#include "ant.h"

class Attack : public Object {
protected:
	//Model3D* myModel = &GloVar::model_ant;
	//Texture* texture = &GloVar::AntTexture;
	float dmg;
	Ant* target;
public:

	void SetTarget(Ant* _target);

	virtual void Draw() = 0;
	virtual void Update() = 0;
};