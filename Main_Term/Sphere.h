#pragma once
#include "transform.h"
#include "model_3d.h"
#include "model_maker.h"
#include <iostream>

extern Model3D m3d;

class Sphere : public Transform
{
	Model3D* model;
public:
	Sphere(float x, float y, float z, float rate) {
		model = &m3d;
		SetPos(glm::vec3(x, y, z));
		SetScale(glm::vec3(rate, rate, rate));
	}
	void draw() {
		model->Draw();
	}
	void update() {
		MoveFront(0.01);
	};
};

