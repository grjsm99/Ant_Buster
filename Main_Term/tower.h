#pragma once
#include "techtree.h"
#include "ant.h"
#include "missile1.h"

class Tower : public Object 
{
	techtree* data;
	Ant* target; // ���� Ÿ���� �ٶ󺸰��ִ� ����
	bool cannonSwitch = false;
	int cool = 0;
	int tx;
	int tz;
public:
	Tower(int x, int z);
	void Update();
	void getNextTarget();
	void Draw();
	void Upgrade(int);
	glm::vec2 towerIndex() { return glm::vec2(tx, tz); };
	glm::vec3 GetCannonHole();
};

