#pragma once
#include "model_3d.h"
#include "global_var.h"

class Attack;	//������ ��������� include�ϸ� ������ ����.(�״�� Ŭ������ �����Ͽ� �����Ѵٰ� �˷��ش�.)

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