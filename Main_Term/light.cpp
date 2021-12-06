#include "light.h"

Light::Light() {
	transform.SetPos(glm::vec3(0, 1, 0));
}

glm::vec3 Light::GetColor() {
	return color;
}

void Light::SetColor(float r, float g, float b) {
	color = glm::vec3(r,g,b);
}