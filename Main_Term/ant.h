#pragma once
#include "model_3d.h"
#include "global_var.h"

class Attack;	//서로의 헤더파일을 include하면 오류가 난다.(그대신 클래스를 선언하여 존재한다고 알려준다.)

class Ant : public Object {
	Model3D* myModel = &GloVar::model_ant;
	Texture* texture = &GloVar::AntTexture;
	float hp;
	float speed;
	float moveDist;
	bool isplusz = true;
	int bounty;

	std::vector<Attack*> pursuers;

	std::vector<std::pair<float, float>> poisonings;
	std::vector<std::pair<float, float>> snowings;

public:
	Ant(int);
	~Ant();

	void Draw();
	bool Update();
	void Attacked(float _dmg);

	void AddSnowing(std::pair<float, float> _newSnowing);
	void AddPoisoning(std::pair<float, float> _newPoisoning);

	void AddPursuer(Attack* _attack);
	void PopPursuer(Attack* _attack);

};