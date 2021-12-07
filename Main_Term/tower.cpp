#include "tower.h"
#include "mainState.h"

Tower::Tower(int x, int z) { // x,z = 0~9
	tx = x;
	tz = z;
	data = &GloVar::root;
	target = NULL;
	transform.SetPos(glm::vec3(x - 4.5, 0, z - 4.5)); // Ÿ�� ������ǥ = -4.5~4.5
	cool = data->getData()->cooldown;
}

void Tower::Upgrade(int type) {
	if(type == 1) data = data->getLeft();
	if(type == 2) data = data->getRight();
	if(type == 3) data = data->getMid();
	if(type == 3) data = data->getPrev();
}

void Tower::Draw() {
	GLuint shaderID = GloVar::shader[2].GetShaderID();

	unsigned int modelLocation = glGetUniformLocation(shaderID, "modelTransform");
	unsigned int normalLocation = glGetUniformLocation(shaderID, "normalTransform");

	//�� Ʈ������
	glm::mat4 modelTransform = transform.GetModelMat();
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelTransform));

	//��� Ʈ������
	glm::mat4 normalTransform = transform.GetNormalMat();
	glUniformMatrix4fv(normalLocation, 1, GL_FALSE, glm::value_ptr(normalTransform));

	data->getData()->myModel->Draw(*(data->getData()->texture));
}

void Tower::Update() {

	if (target == NULL) getNextTarget(); // ���� Ÿ���� �������
	else {
		glm::vec3 towerPos = transform.GetPos(); // Ÿ���� ��ġ
		glm::vec3 targetPos = target->GetTransfromPtr()->GetPos();
		float distance = sqrt(pow(targetPos.x - towerPos.x, 2) + pow(targetPos.z - towerPos.z, 2));
		if (distance > data->getData()->range) { // ��Ÿ����� �������
			target = NULL;
		}
		else {
			cool -= 1;
			transform.SetDir(glm::normalize(glm::vec3(targetPos.x - towerPos.x, 0, targetPos.z - towerPos.z)));
			//�ӽ÷� Ȯ�������� �����ϵ��� ��
			if (cool == 0) {
				Missile1* newMissile1 = new Missile1(GetCannonHole(), transform.GetDir(), target);
				mainState::attacks.push_back(newMissile1);
				cannonSwitch = !cannonSwitch;
				cool = data->getData()->cooldown;
			}
		}
	}
}
void Tower::getNextTarget() {
	float minDistance = 10;
	glm::vec3 towerPos = transform.GetPos(); // Ÿ���� ��ġ

	for (auto it = mainState::ants.begin(); it != mainState::ants.end(); it++) {
		glm::vec3 antPos = (*it)->GetTransfromPtr()->GetPos(); // ������ ��ġ
		
		float distance = sqrt(pow(antPos.x - towerPos.x, 2) + pow(antPos.z - towerPos.z, 2));
		if (distance <= data->getData()->range && distance < minDistance) { // ��Ÿ����� �������
			minDistance = distance;
			target = (*it);

		}
	}
}

glm::vec3 Tower::GetCannonHole() {
	glm::vec3 cannonHolePos(0, 0.4f, 0.4f);	//������ ���̷� ����
	if (cannonSwitch) {	//���� ������ �߻�
		cannonHolePos.x = 0.1f;
	}
	else {	//������ ������ �߻�
		cannonHolePos.x = -0.1f;
	}
	//ȸ��
	cannonHolePos = glm::rotate(glm::mat4(1.0f), atan2(transform.GetDir().x, transform.GetDir().z), glm::vec3(0, 1, 0)) * glm::vec4(cannonHolePos, 1.0f);

	cannonHolePos += transform.GetPos();	//�ڽ��� ��ġ�� �̵�

	return cannonHolePos;

}