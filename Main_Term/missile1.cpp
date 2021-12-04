#include "missile1.h"
#include "mainState.h"



Missile1::Missile1(glm::vec3 _pos, glm::vec3 _dir, Ant* _target) {
	myModel = &GloVar::model_missile1;
	texture = &GloVar::missile1Texture;
	
	transform.SetPos(_pos);
	transform.SetDir(_dir);

	dmg = 10.0f;
	speed = 0.005f;
	spinSpeed = 5.0f;
	target = _target;
}

void Missile1::Draw() {
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

void Missile1::Update() {
	transform.MoveFront(speed);
	if (speed <= 0.2f) {
		speed *= 1.1f;
	}

	if (std::find(mainState::ants.begin(), mainState::ants.end(), target) != mainState::ants.end()) {
		glm::vec3 targetPos = target->GetTransfromPtr()->GetPos();
		transform.TurnTargetSlow(targetPos, spinSpeed);
		if (glm::distance(transform.GetPos(), targetPos) <= 0.5f) {
			//µ¥¹ÌÁö ÁÖ¸é¼­ »èÁ¦µÊ
			target->Attacked(dmg);
			mainState::attacks.erase(std::remove(mainState::attacks.begin(), mainState::attacks.end(), this), mainState::attacks.end());
			delete this;
			return;
		}
	}
	else {
		mainState::attacks.erase(std::remove(mainState::attacks.begin(), mainState::attacks.end(), this), mainState::attacks.end());
		delete this;
		return;
	}
}

