#pragma once
#include "attack.h"

class Missile2 : public Attack {
protected:
	Model3D* myModel;
	Texture* texture;
	float speed;
	float spinSpeed;
	float lifeTime;
public:
	Missile2(glm::vec3 _pos, glm::vec3 _dir, Ant* _target, float _dmg);
	~Missile2();

	void Draw();
	void Update();
};