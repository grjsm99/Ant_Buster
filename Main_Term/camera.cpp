#include "camera.h"

Camera::Camera() {
	transfrom.SetDir(glm::normalize(glm::vec3(0, -1, -2)));
}

glm::vec3 Camera::Eye() {
	return transfrom.GetPos();
}
glm::vec3 Camera::At() {
	return transfrom.GetPos() + transfrom.GetDir();
}
glm::vec3 Camera::Up() {
	return glm::vec3(0, 1, 0);
}

void Camera::Move(glm::vec3 value) {
	transfrom.SetPos(transfrom.GetPos() + value);
}

void Camera::MoveFront(float speed) {
	transfrom.SetPos(transfrom.GetPos() + transfrom.GetDir() * speed);
}

void Camera::RotateLeft(float degree) {
	glm::vec3 currentDir = transfrom.GetDir();
	currentDir = glm::rotate(glm::mat4(1.0f), glm::radians(degree), glm::vec3(0, 1, 0)) * glm::vec4(currentDir, 1.0f);
	transfrom.SetDir(currentDir);
}
void Camera::RotateRight(float degree) {
	glm::vec3 currentDir = transfrom.GetDir();
	currentDir = glm::rotate(glm::mat4(1.0f), glm::radians(-degree), glm::vec3(0, 1, 0)) * glm::vec4(currentDir, 1.0f);
	transfrom.SetDir(currentDir);
}
void Camera::RotateUp(float degree) {
	if (degree <= 0) { return; }

	glm::vec3 y(0, 1, 0);
	glm::vec3 currentDir = transfrom.GetDir();

	float theta = glm::degrees(glm::acos(glm::dot(y, currentDir)));
	if (theta - degree > 0) {
		currentDir = glm::rotate(glm::mat4(1.0f), glm::radians(-degree), glm::cross(y, currentDir)) * glm::vec4(currentDir, 1.0f);
		transfrom.SetDir(currentDir);
	}
}
void Camera::RotateDown(float degree) {
	if (degree <= 0) { return; }

	glm::vec3 y(0, -1, 0);
	glm::vec3 currentDir = transfrom.GetDir();

	float theta = glm::degrees(glm::acos(glm::dot(y, currentDir)));
	if (theta - degree > 0) {
		currentDir = glm::rotate(glm::mat4(1.0f), glm::radians(-degree), glm::cross(y, currentDir)) * glm::vec4(currentDir, 1.0f);
		transfrom.SetDir(currentDir);
	}
}

