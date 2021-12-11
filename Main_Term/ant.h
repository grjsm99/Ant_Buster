#pragma once
#include "model_3d.h"
#include "global_var.h"

class Attack;	//������ ��������� include�ϸ� ������ ����.(�״�� Ŭ������ �����Ͽ� �����Ѵٰ� �˷��ش�.)

class Ant : public Object {
	Model3D* myModel = &GloVar::model_ant;
	Texture* texture = &GloVar::AntTexture;
	float hp;
	float speed = 0.05f;
	float moveDist = 0;
	bool isplusz = true;
	int bounty;

	std::vector<Attack*> pursuers;

public:
	Ant(int);
	~Ant();

	void Draw();
	bool Update();
	void Attacked(float _dmg);

	void AddPursuer(Attack* _attack);
	void PopPursuer(Attack* _attack);

};