#pragma once
#include "model_3d.h"

struct Status {
	Model3D* myModel;
	Texture* texture;
	float range;
	float damage;
	int cost;
	int cooldown; // Ÿ���� ������ �ִ� ������

};

class techtree
{
	Status status;

	techtree* prev; // ������ũ

	techtree* left;
	techtree* mid;
	techtree* right; // ������ũ
	Texture* infoTexture;

public:
	techtree(Model3D* _myModel, Texture* _texture, float _range, float _damage, float _cooldown, int _cost, Texture& _infotexture, int _firerate) {
		status.myModel = _myModel;
		status.texture = _texture;
		status.range = _range;
		status.damage = _damage;
		status.cooldown = _cooldown * 60 / (float)1000;
		status.cost = _cost;
		infoTexture = &_infotexture;

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
	Texture* getInfoTexture() { return infoTexture; };
	techtree* getLeft() { return left; };
	techtree* getRight() { return right; };
	techtree* getMid() { return mid; };
	techtree* getPrev() { return prev; };
	void Upgrade(); // ���ݷ� ���׷��̵� ��..
	
};

