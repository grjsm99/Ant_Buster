#pragma once
#include "object.h"
#include <glew.h>
class Camera : public Object {
	
	glm::vec3 cameraDirection;
	glm::vec3 cameraUp;
public:
	Camera();

};