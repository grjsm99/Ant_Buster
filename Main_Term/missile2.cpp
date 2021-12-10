#include "missile2.h"
#include "mainState.h"



Missile2::Missile2(glm::vec3 _pos, glm::vec3 _dir, Ant* _target, float _dmg) {
	myModel = &GloVar::model_missile2;
	texture = &GloVar::missile2Texture;

	transform.SetPos(_pos);
	transform.SetDir(_dir);

	dmg = _dmg;
	speed = 0.008f;
	spinSpeed = 4.0f;
	lifeTime = 8.0f;
	target = _target;
	if (target != 0) {
		target->AddPursuer(this);
	}
}

Missile2::~Missile2() {
	mainState::attacks.erase(std::remove(mainState::attacks.begin(), mainState::attacks.end(), this), mainState::attacks.end());
	if (target != 0) {
		target->PopPursuer(this);
	}
}

void Missile2::Draw() {
	GLuint shaderID = GloVar::shader[2].GetShaderID();

	unsigned int modelLocation = glGetUniformLocation(shaderID, "modelTransform");
	unsigned int normalLocation = glGetUniformLocation(shaderID, "normalTransform");

	//모델 트랜스폼
	glm::mat4 modelTransform = transform.GetModelMat();
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelTransform));

	//노멀 트랜스폼
	glm::mat4 normalTransform = transform.GetNormalMat();
	glUniformMatrix4fv(normalLocation, 1, GL_FALSE, glm::value_ptr(normalTransform));

	myModel->Draw(*texture);
}

void Missile2::Update() {
	lifeTime -= 1 / 60.f;
	if (lifeTime <= 0) {
		delete this;
		return;
	}

	transform.MoveFront(speed);
	if (speed <= 0.18f) {
		speed *= 1.1f;
	}

	if (lifeTime < 6.5f) {
		if (target != 0) {	//타겟이 있을경우
			glm::vec3 targetPos = target->GetTransfromPtr()->GetPos();
			transform.TurnTargetSlow(targetPos, spinSpeed);
			if (glm::distance(transform.GetPos(), targetPos) <= 0.5f) {
				//데미지 주면서 삭제됨
				target->Attacked(dmg);
				delete this;
				return;
			}
		}
		else {	//타겟이 없을경우

			float min_distance = 9999.9f;
			Ant* newTarget = 0;
			for (int i = 0; i < mainState::ants.size(); ++i) {
				float distance = glm::distance(transform.GetPos(), mainState::ants[i]->GetTransfromPtr()->GetPos());
				if (distance < min_distance) {
					min_distance = distance;
					newTarget = mainState::ants[i];
				}
			}

			if (newTarget != 0) {
				target = newTarget;
				target->AddPursuer(this);
			}

		}
	}

}

