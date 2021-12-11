#include "ant.h"
#include "mainState.h"

Ant::Ant(int stage) {
	hp = stage * 14;
	speed = 0.05f;
	moveDist = 0;
	transform.SetPos(glm::vec3(-4.5, 0, -4.5));
	bounty = 1;
}

Ant::~Ant() {
	mainState::ants.erase(std::remove(mainState::ants.begin(), mainState::ants.end(), this), mainState::ants.end());
	for (int i = 0; i < pursuers.size(); ++i) {
		pursuers[i]->SetTarget(0);
	}
	for (int i = 0; i < mainState::towers.size(); ++i) {
		if (mainState::towers[i]->getTarget() == this) mainState::towers[i]->InitTarget();
	}
	pursuers.clear();
	pursuers.shrink_to_fit();
}

void Ant::Draw() {
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

bool Ant::Update() {
	texture = &GloVar::AntTexture;

	if (poisonings.size() > 0) {
		texture = &GloVar::AntPoisoningTexture;
	}
	for (int i = 0; i < poisonings.size(); ++i) {
		//지속시간 적용
		poisonings[i].first -= 1.0f / 60.0f;
		if (poisonings[i].first <= 0) {
			poisonings.erase(poisonings.begin() + i);
			i--;
			continue;
		}

		//데미지 적용(초당 poisonings[i].second 만큼)
		hp -= poisonings[i].second / 60.0f;
		if (hp <= 0.0f) {
			mainState::gold += bounty;
			delete this;
			return false;
		}
	}

	float realSpeed = speed;
	if (snowings.size() > 0) {
		texture = &GloVar::AntSnowingTexture;
	}
	for (int i = 0; i < snowings.size(); ++i) {
		//지속시간 적용
		snowings[i].first -= 1.0f / 60.0f;
		if (snowings[i].first <= 0) {
			snowings.erase(snowings.begin() + i);
			i--;
			continue;
		}

		//둔화 적용
		realSpeed *= (1.0f - snowings[i].second);
	}

	transform.MoveFront(realSpeed);
	moveDist += realSpeed;
	glm::vec3 dir = transform.GetDir();
	glm::vec3 pos = transform.GetPos();
	if (dir.x != 0) {
		if (moveDist >= 2) {
			transform.SetDir(glm::vec3(0, 0, 1 - 2 * isplusz));
			isplusz = !isplusz;
			moveDist = 0;
		}
		else if (pos.x >= 4.5) {
			delete this;
			return true;
		}
	}
	else if (moveDist >= 9)
	{ 
		transform.SetDir(glm::vec3(1, 0, 0));
		moveDist = 0;
	}
	return false;
}

void Ant::Attacked(float _dmg) {
	hp -= _dmg;
	if (hp <= 0.0f) {
		mainState::gold += bounty;
		delete this;
		return;
	}
}

void Ant::AddPursuer(Attack* _attack) {
	pursuers.push_back(_attack);
}

void Ant::PopPursuer(Attack* _attack) {
	for (int i = 0; i < pursuers.size(); ++i) {
		if (pursuers[i] == _attack) {
			pursuers.erase(pursuers.begin() + i);
			return;
		}
	}
}

void Ant::AddSnowing(std::pair<float, float> _newSnowing) {
	snowings.push_back(_newSnowing);
}
void Ant::AddPoisoning(std::pair<float, float> _newPoisoning) {
	poisonings.push_back(_newPoisoning);
}