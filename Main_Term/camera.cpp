#include "camera.h"

Camera::Camera() {
	GetTrans().SetPos(glm::vec3(0, 5, 0));
	cameraDirection = glm::vec3(0, 0, 0);
	cameraUp = glm::vec3(0, 0, 1);
}

