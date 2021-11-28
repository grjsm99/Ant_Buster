#pragma once
#include "object.h"
#include <gl/glew.h>
class Camera : public Object {
public:
	Camera();

	glm::vec3 Eye();
	glm::vec3 At();
	glm::vec3 Up();

	void Move(glm::vec3 value);
	void MoveFront(float speed);
	void RotateLeft(float degree);
	void RotateRight(float degree);
	void RotateUp(float degree);
	void RotateDown(float degree);
};