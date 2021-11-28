#pragma once
#include "object.h"
#include <gl/glew.h>
class Light : public Object {
private:
	glm::vec3 color = glm::vec3(1, 1, 1);
public:
	Light();
	glm::vec3 GetColor();
};
