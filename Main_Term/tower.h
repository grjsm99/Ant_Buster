#pragma once
#include "techtree.h"
#include "ant.h"

class Tower : public Object 
{
	techtree* data;
	Ant* target; // 현재 타워가 바라보고있는 개미


public:
	Tower(int x, int z);
	void Update();
	void getNextTarget();
	void Draw();
};

