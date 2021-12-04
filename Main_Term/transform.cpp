#include "transform.h"
#include <algorithm>
#include <iostream>

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
	//�̵�
	modelMat = glm::translate(modelMat, pos);
	//ȸ��
	glm::vec3 z(0, 0, 1);
	float theta = glm::degrees(glm::acos(glm::dot(z, dir)));
	if (0 < theta) {
		if (theta < 180) {
			modelMat = glm::rotate(modelMat, glm::radians(theta), glm::cross(glm::vec3(0, 0, 1), dir));	//������ ���������� theta��ŭ ȸ��
		}
		else {
			modelMat = glm::rotate(modelMat, glm::radians(theta), glm::vec3(0, 1, 0));	//������ ���������� theta��ŭ ȸ��
		}
	}
	//����
	modelMat = glm::scale(modelMat, scale);

	return modelMat;
}
glm::mat4 Transform::GetNormalMat() {
	glm::mat4 normalMat(1.0f);

	//ȸ��
	glm::vec3 z(0, 0, 1);
	float theta = glm::degrees(glm::acos(glm::dot(z, dir)));
	if (0 < theta) {
		if (theta < 180) {
			normalMat = glm::rotate(normalMat, glm::radians(theta), glm::cross(glm::vec3(0, 0, 1), dir));	//������ ���������� theta��ŭ ȸ��
		}
		else {
			normalMat = glm::rotate(normalMat, glm::radians(theta), glm::vec3(0, 1, 0));	//������ ���������� theta��ŭ ȸ��
		}
	}
	//����
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
	glm::vec3 targetDir = glm::normalize(targetPos - pos);
	float theta = glm::degrees(glm::acos( std::min( glm::dot(targetDir, dir), 1.0f ) ));	//���̰�

	if (theta < spinSpeed) {	//spinSpeed ���� �ȿ� Ÿ���� �ٶ󺼼� ���� ���
		TurnTarget(targetPos);
	}
	else {
		if (theta < 180) {	//180���� ���� ���� ���
			glm::mat4 rotationMat(1.0f);
			rotationMat = glm::rotate(rotationMat, glm::radians(spinSpeed), glm::cross(dir, targetDir));	//������ ���������� theta��ŭ ȸ��
			dir = glm::normalize(glm::vec3(rotationMat * glm::vec4(dir, 1.0f)));
		}
		else {	//�� �ݴ� ������ ���(���������� ���͸� ��¦ ���� �ش�.)
			dir += glm::vec3(rand() % 101 - 50, rand() % 101 - 50, rand() % 101 - 50) / 500.f;
			dir = glm::normalize(dir);
		}
	}

}

void Transform::MultiplySize(float value) {
	scale *= value;
}