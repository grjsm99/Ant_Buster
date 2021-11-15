#include "transform.h"
#include <iostream>
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

void Transform::MoveFront(float speed) {
	// (0,0,speed)벡터를 내가 바라노는 방향이 되도록 행렬을 곱셈하여
	glm::mat4 matrix(1.0f);
	matrix = glm::rotate(matrix, glm::radians(rotation.z), glm::vec3(1, 0, 1));
	matrix = glm::rotate(matrix, glm::radians(rotation.y), glm::vec3(1, 1, 0));
	matrix = glm::rotate(matrix, glm::radians(rotation.x), glm::vec3(1, 0, 0));
	glm::vec3 movePos = matrix * glm::vec4(0, 0, speed, 0);	

	//구한 벡터를 현재의 위치에 더한다.
	pos += movePos;
}
void Transform::MovePoint(float speed, glm::vec3 targetPos) {
	glm::vec3 movePos = targetPos - pos;
	pos += glm::normalize(movePos) * speed;
}

void Transform::TurnBody(float radian) {
	rotation.y += radian;
}
void Transform::TurnTarget(glm::vec3 targetPos) {
	glm::vec3 z(0, 0, 1);

	//외적의 높이를 구함( 이걸로 0~180도인지 180~360인지를 구분할수 있다.)
	float l = glm::cross(z, targetPos).y;
	//세타를 구함
	float theta = glm::acos(glm::dot(z, targetPos) / (glm::length(z) * glm::length(targetPos)));
	// l를 이용해 진짜 각도값을 구한다.
	float degree;
	if (l >= 0) {
		degree = glm::degrees(theta);
	}
	else {
		degree = 360 - glm::degrees(theta);
	}

	//각도를 적용한다.
	rotation.y = degree;
}

void Transform::MultiplySize(float value) {
	scale *= value;
}