#include "ant_nest.h"
#include "mainState.h"

AntNest::AntNest() {
	transform.SetPos(glm::vec3(-4, 0, -4));
}

void AntNest::Draw() {
	GLuint shaderID = GloVar::shader[2].GetShaderID();

	unsigned int modelLocation = glGetUniformLocation(shaderID, "modelTransform");
	unsigned int normalLocation = glGetUniformLocation(shaderID, "normalTransform");

	//�� Ʈ������
	glm::mat4 modelTransform = transform.GetModelMat();
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelTransform));

	//��� Ʈ������
	glm::mat4 normalTransform = transform.GetNormalMat();
	glUniformMatrix4fv(normalLocation, 1, GL_FALSE, glm::value_ptr(normalTransform));

	myModel->Draw(*texture);
}

void AntNest::Update() {
	if (mainState::ants.size() < 5) {
		Ant* newAnt = new Ant();
		mainState::ants.push_back(newAnt);
	}
}



