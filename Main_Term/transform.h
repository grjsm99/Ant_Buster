#pragma once

#include <glm/gtc/matrix_transform.hpp>

class Transform {
private:
	glm::vec3 pos;
	glm::vec3 dir;	//dir�� ���������̴� (�������Ͱ� �ǵ��� �������)
	glm::vec3 scale;

public:
	Transform();
	Transform(glm::vec3 _pos, glm::vec3 _dir, glm::vec3 _scale);

	void SetPos(glm::vec3 _pos) { pos = _pos; }
	void SetDir(glm::vec3 _dir) { dir = glm::normalize(_dir); }
	void SetScale(glm::vec3 _scale) { scale = _scale; }

	glm::vec3 GetPos() { return pos; }
	glm::vec3 GetDir() { return dir; }
	glm::vec3 GetScale() { return scale; }

	glm::mat4 GetModelMat();
	glm::mat4 GetNormalMat();

	// �ٶ󺸴� �������� �̵�
	void MoveFront(float speed);
	// Ÿ���������� �̵�
	void MovePoint(float speed, glm::vec3 targetPos);

	// Ÿ�� �������� ������ �ٲ۴�.
	void TurnTarget(glm::vec3 targetPos);
	// Ÿ�� �������� õõ��(spinSpeed��ŭ) ������ �ٲ۴�.
	void TurnTargetSlow(glm::vec3 targetPos, float spinSpeed);

	// scale �� value�� ���Ѵ�.
	void MultiplySize(float value);

};
