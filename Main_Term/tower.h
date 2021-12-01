#pragma once
#include "techtree.h"
#include "ant.h"

class Tower : public Object 
{
	techtree* data;
	Ant* target; // ���� Ÿ���� �ٶ󺸰��ִ� ����


public:
	Tower(int x, int z);
	void Update();
	void getNextTarget();
	void Draw();
};

