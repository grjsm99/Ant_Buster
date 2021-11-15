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
	//�̵�
	modelMat = glm::translate(modelMat, pos);
	//ȸ��
	modelMat = glm::rotate(modelMat, glm::radians(rotation.z), glm::vec3(0, 0, 1));
	modelMat = glm::rotate(modelMat, glm::radians(rotation.y), glm::vec3(0, 1, 0));
	modelMat = glm::rotate(modelMat, glm::radians(rotation.x), glm::vec3(1, 0, 0));
	//����
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
	// (0,0,speed)���͸� ���� �ٶ��� ������ �ǵ��� ����� �����Ͽ�
	glm::mat4 matrix(1.0f);
	matrix = glm::rotate(matrix, glm::radians(rotation.z), glm::vec3(1, 0, 1));
	matrix = glm::rotate(matrix, glm::radians(rotation.y), glm::vec3(1, 1, 0));
	matrix = glm::rotate(matrix, glm::radians(rotation.x), glm::vec3(1, 0, 0));
	glm::vec3 movePos = matrix * glm::vec4(0, 0, speed, 0);	

	//���� ���͸� ������ ��ġ�� ���Ѵ�.
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

	//������ ���̸� ����( �̰ɷ� 0~180������ 180~360������ �����Ҽ� �ִ�.)
	float l = glm::cross(z, targetPos).y;
	//��Ÿ�� ����
	float theta = glm::acos(glm::dot(z, targetPos) / (glm::length(z) * glm::length(targetPos)));
	// l�� �̿��� ��¥ �������� ���Ѵ�.
	float degree;
	if (l >= 0) {
		degree = glm::degrees(theta);
	}
	else {
		degree = 360 - glm::degrees(theta);
	}

	//������ �����Ѵ�.
	rotation.y = degree;
}

void Transform::MultiplySize(float value) {
	scale *= value;
}