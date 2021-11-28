#pragma once

#include <glm/gtc/matrix_transform.hpp>

class Transform {
private:
	glm::vec3 pos;
	glm::vec3 dir;	//dir은 단위벡터이다 (단위벡터가 되도록 해줘야함)
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

	// 바라보는 방향으로 이동
	void MoveFront(float speed);
	// 타켓지점으로 이동
	void MovePoint(float speed, glm::vec3 targetPos);

	// 타겟 방향으로 방향을 바꾼다.
	void TurnTarget(glm::vec3 targetPos);
	// 타겟 방향으로 천천히(spinSpeed만큼) 방향을 바꾼다.
	void TurnTargetSlow(glm::vec3 targetPos, float spinSpeed);

	// scale 에 value를 곱한다.
	void MultiplySize(float value);

};
