#include "ant.h"
#include "mainState.h"

Ant::Ant() {
	transform.SetPos(glm::vec3(-4, 0, -4));
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

void Ant::Update() {
	transform.MoveFront(0.01);
}

void Ant::Attacked(float _dmg) {
	hp -= _dmg;
	if (hp <= 0.0f) {
		mainState::ants.erase(std::remove(mainState::ants.begin(), mainState::ants.end(), this), mainState::ants.end());
		delete this;
		return;
	}
}