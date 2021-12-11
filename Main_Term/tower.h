#pragma once
#include "techtree.h"
#include "ant.h"
#include "missile1.h"
#include "missile2.h"

class Tower : public Object 
{
	techtree* data;
	Ant* target; // 현재 타워가 바라보고있는 개미
	bool cannonSwitch = false;
	int cool = 0;
	int tx;
	int tz;
public:
	bool operator==(const Tower& t) {
		std::cout << this->tx << "," << t.tx << ", " << this->tz << t.tz << std::endl; return (this->tx == t.tx && this->tz == t.tz);
	};
	Tower(int x, int z);
	void Update();
	void getNextTarget();
	void Draw();
	void Upgrade(int);
	techtree* getTechTree() { return data; };
	Ant* getTarget() { return target; };
	void InitTarget() { target = NULL; };
	glm::vec2 towerIndex() { return glm::vec2(tx, tz); };
	glm::vec3 GetCannonHole(Status*);
};

