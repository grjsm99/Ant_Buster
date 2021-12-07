#pragma once
#include "attack.h"

class Missile1 : public Attack {
protected:
	Model3D* myModel;
	Texture* texture;
	float speed;
	float spinSpeed;
	float lifeTime;
public:
	Missile1(glm::vec3 _pos, glm::vec3 _dir, Ant* _target);
	~Missile1();

	void Draw();
	void Update();
};