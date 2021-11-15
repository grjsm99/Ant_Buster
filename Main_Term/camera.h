#pragma once
#include "transform.h"
#include <glew.h>
class Camera : public Transform {

	glm::vec3 cameraDirection;
	glm::vec3 cameraUp;
public:
	Camera() {
		SetPos(glm::vec3(0, 5, 0));
		cameraDirection = glm::vec3(0, 0, 0);
		cameraUp = glm::vec3(0, 0, 1);
	}
	void draw() {};
	glm::vec3 camPos() { return GetPos(); };
	glm::vec3 camDirec() { return cameraDirection; };
	glm::vec3 camUp() { return cameraUp; };
};