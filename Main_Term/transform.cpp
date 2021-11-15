#include "transform.h"

Transform::Transform() {
	glm::vec3 pos = glm::vec3(0, 0, 0);
	glm::vec3 rotation = glm::vec3(0, 0, 0);
	glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
}

Transform::Transform(glm::vec3 _pos, glm::vec3 _rotation, glm::vec3 _scale) {
	glm::vec3 pos = _pos;
	glm::vec3 rotation = _rotation;
	glm::vec3 scale = _scale;
}

glm::mat4 Transform::GetModelMat() {
	glm::mat4 modelMat(1.0f);
	//이동
	modelMat = glm::translate(modelMat, pos);
	//회전
	modelMat = glm::rotate(modelMat, glm::radians(rotation.z), glm::vec3(0, 0, 1));
	modelMat = glm::rotate(modelMat, glm::radians(rotation.y), glm::vec3(0, 1, 0));
	modelMat = glm::rotate(modelMat, glm::radians(rotation.x), glm::vec3(1, 0, 0));
	//신축
	modelMat = glm::scale(modelMat, scale);

	return modelMat;
}
glm::mat4 Transform::GetNormalMat() {
	glm::mat4 modelMat(1.0f);

	modelMat = glm::rotate(modelMat, glm::radians(rotation.z), glm::vec3(0, 0, 1));
	modelMat = glm::rotate(modelMat, glm::radians(rotation.y), glm::vec3(0, 1, 0));
	modelMat = glm::rotate(modelMat, glm::radians(rotation.x), glm::vec3(1, 0, 0));
	return modelMat;
}