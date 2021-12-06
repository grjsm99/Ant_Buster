#pragma once
#include "model_3d.h"

struct Status {
	Model3D* myModel;
	Texture* texture;
	float range;
	float damage;
	float cooldown; // Ÿ���� ������ �ִ� ������
};

class techtree
{
	Status status;

	techtree* prev; // ������ũ

	techtree* left;
	techtree* mid;
	techtree* right; // ������ũ
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
	void Upgrade(); // ���ݷ� ���׷��̵� ��..
	
};

