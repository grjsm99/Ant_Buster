#include "ant.h"
#include "mainState.h"

Ant::Ant() {
	transform.SetPos(glm::vec3(-4.5, 0, -4.5));
	bounty = 1;
}

Ant::~Ant() {
	mainState::ants.erase(std::remove(mainState::ants.begin(), mainState::ants.end(), this), mainState::ants.end());
	for (int i = 0; i < pursuers.size(); ++i) {
		pursuers[i]->SetTarget(0);
	}
	pursuers.clear();
	pursuers.shrink_to_fit();
}

void Ant::Draw() {
	GLuint shaderID = GloVar::shader[2].GetShaderID();

	unsigned int modelLocation = glGetUniformLocation(shaderID, "modelTransform");
	unsigned int normalLocation = glGetUniformLocation(shaderID, "normalTransform");

	//¸ðµ¨ Æ®·£½ºÆû
	glm::mat4 modelTransform = transform.GetModelMat();
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelTransform));

	//³ë¸Ö Æ®·£½ºÆû
	glm::mat4 normalTransform = transform.GetNormalMat();
	glUniformMatrix4fv(normalLocation, 1, GL_FALSE, glm::value_ptr(normalTransform));

	myModel->Draw(*texture);
}

bool Ant::Update() {
	transform.MoveFront(speed);
	moveDist += speed;
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