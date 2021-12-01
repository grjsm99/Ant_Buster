#include "tower.h"
#include "mainState.h"

Tower::Tower(int x, int z) { // x,z = 0~9

	data = &GloVar::root;
	target = NULL;
	transform.SetPos(glm::vec3(x - 4.5, 0, z - 4.5)); // 타워 중점좌표 = -4.5~4.5
}



void Tower::Draw() {
	GLuint shaderID = GloVar::shader[2].GetShaderID();

	unsigned int modelLocation = glGetUniformLocation(shaderID, "modelTransform");
	unsigned int normalLocation = glGetUniformLocation(shaderID, "normalTransform");

	//모델 트랜스폼
	glm::mat4 modelTransform = transform.GetModelMat();
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelTransform));

	//노멀 트랜스폼
	glm::mat4 normalTransform = transform.GetNormalMat();
	glUniformMatrix4fv(normalLocation, 1, GL_FALSE, glm::value_ptr(normalTransform));

	data->getData()->myModel->Draw(*(data->getData()->texture));
}

void Tower::Update() {

	if (target == NULL) getNextTarget(); // 현재 타겟이 없을경우
	else {
		glm::vec3 towerPos = transform.GetPos(); // 타워의 위치
		glm::vec3 targetPos = target->GetTransfromPtr()->GetPos();
		float distance = sqrt(pow(targetPos.x - towerPos.x, 2) + pow(targetPos.z - towerPos.z, 2));
		if (distance > data->getData()->range) { // 사거리내의 가까운적
			target = NULL;
		}
		else {
			transform.SetDir(glm::normalize(glm::vec3(targetPos.x - towerPos.x, 0, targetPos.z - towerPos.z)));
		}
	}
}
void Tower::getNextTarget() {
	float maxDistance = 0;
	glm::vec3 towerPos = transform.GetPos(); // 타워의 위치

	for (auto it = mainState::ants.begin(); it != mainState::ants.end(); it++) {
		glm::vec3 antPos = (*it)->GetTransfromPtr()->GetPos(); // 개미의 위치
		
		float distance = sqrt(pow(antPos.x - towerPos.x, 2) + pow(antPos.z - towerPos.z, 2));
		if (distance <= data->getData()->range && distance > maxDistance) { // 사거리내의 가까운적
			target = (*it);

		}
	}
}