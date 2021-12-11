#include "ant_nest.h"
#include "mainState.h"

AntNest::AntNest() {
	transform.SetPos(glm::vec3(-4.5, 0, -4.5));
}

void AntNest::Draw() {
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

void AntNest::Update() {
	cool--;
	if (cool <= 0) {
		antSpawnCount++;
		cool = cooldown;
		Ant* newAnt = new Ant(stage);
		mainState::ants.push_back(newAnt);
		if (antSpawnCount % 10 == 0)	stage++;
		if (antSpawnCount % 20 == 0 && cooldown > 60) cooldown--;
	}
}



