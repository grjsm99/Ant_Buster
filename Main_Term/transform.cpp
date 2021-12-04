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
	//이동
	modelMat = glm::translate(modelMat, pos);
	//회전
	glm::vec3 z(0, 0, 1);
	float theta = glm::degrees(glm::acos(glm::dot(z, dir)));
	if (0 < theta) {
		if (theta < 180) {
			modelMat = glm::rotate(modelMat, glm::radians(theta), glm::cross(glm::vec3(0, 0, 1), dir));	//외적을 기준축으로 theta만큼 회전
		}
		else {
			modelMat = glm::rotate(modelMat, glm::radians(theta), glm::vec3(0, 1, 0));	//외적을 기준축으로 theta만큼 회전
		}
	}
	//신축
	modelMat = glm::scale(modelMat, scale);

	return modelMat;
}
glm::mat4 Transform::GetNormalMat() {
	glm::mat4 normalMat(1.0f);

	//회전
	glm::vec3 z(0, 0, 1);
	float theta = glm::degrees(glm::acos(glm::dot(z, dir)));
	if (0 < theta) {
		if (theta < 180) {
			normalMat = glm::rotate(normalMat, glm::radians(theta), glm::cross(glm::vec3(0, 0, 1), dir));	//외적을 기준축으로 theta만큼 회전
		}
		else {
			normalMat = glm::rotate(normalMat, glm::radians(theta), glm::vec3(0, 1, 0));	//외적을 기준축으로 theta만큼 회전
		}
	}
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
	glm::vec3 targetDir = glm::normalize(targetPos - pos);
	float theta = glm::degrees(glm::acos( std::min( glm::dot(targetDir, dir), 1.0f ) ));	//사이각

	if (theta < spinSpeed) {	//spinSpeed 각도 안에 타켓을 바라볼수 있을 경우
		TurnTarget(targetPos);
	}
	else {
		if (theta < 180) {	//180도가 넘지 않을 경우
			glm::mat4 rotationMat(1.0f);
			rotationMat = glm::rotate(rotationMat, glm::radians(spinSpeed), glm::cross(dir, targetDir));	//외적을 기준축으로 theta만큼 회전
			dir = glm::normalize(glm::vec3(rotationMat * glm::vec4(dir, 1.0f)));
		}
		else {	//정 반대 방향일 경우(랜덤값으로 벡터를 살짝 흔들어 준다.)
			dir += glm::vec3(rand() % 101 - 50, rand() % 101 - 50, rand() % 101 - 50) / 500.f;
			dir = glm::normalize(dir);
		}
	}

}

void Transform::MultiplySize(float value) {
	scale *= value;
}