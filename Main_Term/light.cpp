#include "light.h"

Light::Light() {
	transfrom.SetPos(glm::vec3(0, 1, 0));
}

glm::vec3 Light::GetColor() {
	return color;
}