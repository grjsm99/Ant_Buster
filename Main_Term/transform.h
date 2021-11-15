#pragma once

#include <glm/gtc/matrix_transform.hpp>

class Transform {
private:
	glm::vec3 pos;
	glm::vec3 rotation;
	glm::vec3 scale;

public:
	Transform();
	Transform(glm::vec3 _pos, glm::vec3 _rotation, glm::vec3 _scale);

	void SetPos(glm::vec3 _pos) { pos = _pos; }
	void SetRotation(glm::vec3 _rotation) { rotation = _rotation; }
	void SetScale(glm::vec3 _scale) { scale = _scale; }

	glm::vec3 GetPos() { return pos; }
	glm::vec3 GetRotation() { return rotation; }
	glm::vec3 GetScale() { return scale; }

	glm::mat4 GetModelMat();
	glm::mat4 GetNormalMat();

};
