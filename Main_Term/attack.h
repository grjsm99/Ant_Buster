#pragma once
#include "ant.h"

class Attack : public Object {
protected:
	//Model3D* myModel = &GloVar::model_ant;
	//Texture* texture = &GloVar::AntTexture;
	float dmg;
	std::pair<float, float> poison = std::pair<float, float>(0, 0);
	std::pair<float, float> snow = std::pair<float, float>(0, 0);
	Ant* target;
public:

	void SetTarget(Ant* _target);
	void SetPoison(std::pair<float, float> _poison);
	void SetSnow(std::pair<float, float> _snow);

	virtual void Draw() = 0;
	virtual void Update() = 0;
};