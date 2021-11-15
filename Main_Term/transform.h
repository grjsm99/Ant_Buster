#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
class Transform {
private:
	glm::vec3 pos;
	glm::vec3 rotation;
	glm::vec3 scale;
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	Transform();
	Transform(glm::vec3 _pos, glm::vec3 _rotation, glm::vec3 _scale);

	void SetPos(glm::vec3 _pos) { pos = _pos;}
	void SetRotation(glm::vec3 _rotation) { rotation = _rotation; }
	void SetScale(glm::vec3 _scale) { scale = _scale; }

	glm::vec3 GetPos() { return pos; }
	glm::vec3 GetRotation() { return rotation; }
	glm::vec3 GetScale() { return scale; }

	glm::mat4 GetModelMat();
	glm::mat4 GetNormalMat();

	// �ٶ󺸴� �������� �̵�
	void MoveFront(float speed);
	// Ÿ���������� �̵�
	void MovePoint(float speed, glm::vec3 targetPos);

	// y������ radian��ŭ ȸ��
	void TurnBody(float radian);
	// Ÿ�� �������� y������ �ٲ۴�.
	void TurnTarget(glm::vec3 targetPos);

	// scale �� value�� ���Ѵ�.
	void MultiplySize(float value);

};
