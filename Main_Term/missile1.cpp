#include "missile1.h"
#include "mainState.h"



Missile1::Missile1(glm::vec3 _pos, glm::vec3 _dir, Ant* _target, float _dmg) {
	myModel = &GloVar::model_missile1;
	texture = &GloVar::missile1Texture;
	transform.SetPos(_pos);
	transform.SetDir(_dir);

	dmg = _dmg;
	speed = 0.005f;
	spinSpeed = 5.0f;
	lifeTime = 1.0f;
	target = _target;
	if (target != 0) {
		target->AddPursuer(this);
	}
}

Missile1::~Missile1() {
	mainState::attacks.erase(std::remove(mainState::attacks.begin(), mainState::attacks.end(), this), mainState::attacks.end());
	if (target != 0) {
		target->PopPursuer(this);
	}
}

void Missile1::Draw() {
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

void Missile1::Update() {


	transform.MoveFront(speed);
	if (speed <= 0.2f) {
		speed *= 1.1f;
	}

	if (target != 0) {	//타겟이 있을경우
		glm::vec3 targetPos = target->GetTransfromPtr()->GetPos();
		transform.TurnTargetSlow(targetPos, spinSpeed);
		if (glm::distance(transform.GetPos(), targetPos) <= 0.5f) {
			//데미지 주면서 삭제됨
			if (snow != std::pair<float, float>(0, 0)) {
				target->AddSnowing(snow);
			}
			if (poison != std::pair<float, float>(0, 0)) {
				target->AddPoisoning(poison);
			}
			target->Attacked(dmg);
			delete this;
			return;
		}
	}
	else {	//타겟이 없을경우
		lifeTime -= 1 / 60.f;
		if (lifeTime <= 0) {
			delete this;
			return;
		}
	}
}

