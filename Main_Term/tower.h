#pragma once
#include "techtree.h"
#include "ant.h"
#include "missile1.h"

class Tower : public Object 
{
	techtree* data;
	Ant* target; // ���� Ÿ���� �ٶ󺸰��ִ� ����
	bool cannonSwitch = false;

public:
	Tower(int x, int z);
	void Update();
	void getNextTarget();
	void Draw();
	void Upgrade(int);
	glm::vec3 GetCannonHole();
};

