#pragma once
#include "model_3d.h"

struct Status {
	Model3D* myModel;
	Texture* texture;
	float range;
	float damage;
	float cooldown; // 타워가 가지고 있는 성질들
};

class techtree
{
	Status status;

	techtree* prev; // 이전테크

	techtree* left;
	techtree* mid;
	techtree* right; // 다음테크
public:
	techtree(Model3D* _myModel, Texture* _texture, float _range, float _damage, float _cooldown) {
		status.myModel = _myModel;
		status.texture = _texture;
		status.range = _range;
		status.damage = _damage;
		status.cooldown = _cooldown;

		prev = NULL;
		left = NULL;
		mid = NULL;
		right = NULL;
	};
	Status* getData() { return &status; }
	void setLeft(techtree*);
	void setRight(techtree*);
	void setMid(techtree*);
	void setPrev(techtree*);

	techtree* getLeft() { return left; };
	techtree* getRight() { return right; };
	techtree* getMid() { return mid; };
	techtree* getPrev() { return prev; };
	void Upgrade(); // 공격력 업그레이드 등..
	
};

