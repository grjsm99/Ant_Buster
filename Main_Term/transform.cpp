#include "transform.h"

Transform::Transform() {
	pos = glm::vec3(0, 0, 0);
	dir = glm::vec3(0, 0, 1);
	scale = glm::vec3(1.0f, 1.0f, 1.0f);
}

Transform::Transform(glm::vec3 _pos, glm::vec3 _dir, glm::vec3 _scale) {
	pos = _pos;
	dir = _dir;
	scale = _scale;
}

glm::mat4 Transform::GetModelMat() {
	glm::mat4 modelMat(1.0f);
	//이동
	modelMat = glm::translate(modelMat, pos);
	//회전
	glm::vec3 z(0, 0, 1);
	float theta = glm::degrees(glm::acos(glm::dot(z, dir)));	
	modelMat = glm::rotate(modelMat, glm::radians(theta), glm::cross( glm::vec3(0, 0, 1), dir));	//외적을 기준축으로 theta만큼 회전
	//신축
	modelMat = glm::scale(modelMat, scale);

	return modelMat;
}
glm::mat4 Transform::GetNormalMat() {
	glm::mat4 normalMat(1.0f);

	//회전
	glm::vec3 z(0, 0, 1);
	float theta = glm::degrees(glm::acos(glm::dot(z, dir)));
	normalMat = glm::rotate(normalMat, glm::radians(theta), glm::cross(glm::vec3(0, 0, 1), dir));	//외적을 기준축으로 theta만큼 회전
	//신축
	normalMat = glm::transpose(glm::inverse(glm::scale(normalMat, scale)));
	return normalMat;
}

void Transform::MoveFront(float speed) {
	pos += dir * speed;
}
void Transform::MovePoint(float speed, glm::vec3 targetPos) {
	glm::vec3 moveDir = glm::normalize(targetPos - pos);
	pos += moveDir * speed;
}

void Transform::TurnTarget(glm::vec3 targetPos) {
	dir = glm::normalize(targetPos - pos);
}
void Transform::TurnTargetSlow(glm::vec3 targetPos, float spinSpeed) {
	glm::vec3 z(0, 0, 1);
	float theta = glm::degrees(glm::acos(glm::dot(z, dir)));	//사이각
	//0도와 180도 일경우 오류가 날수 있다. (추후 수정할것)
	if (theta < spinSpeed) {
		TurnTarget(targetPos);
	}
	else {
		glm::mat4 rotationMat(1.0f);
		rotationMat = glm::rotate(rotationMat, glm::radians(theta), glm::cross(glm::vec3(0, 0, 1), dir));	//외적을 기준축으로 theta만큼 회전
		dir = glm::normalize(glm::vec3(rotationMat * glm::vec4(dir, 1.0f)));
	}

}

void Transform::MultiplySize(float value) {
	scale *= value;
}