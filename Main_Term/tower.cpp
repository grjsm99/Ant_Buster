#include "tower.h"
#include "mainState.h"

Tower::Tower(int x, int z) { // x,z = 0~9
	tx = x;
	tz = z;
	data = &GloVar::root;
	target = NULL;
	transform.SetPos(glm::vec3(x - 4.5, 0, z - 4.5)); // 타워 중점좌표 = -4.5~4.5
	cool = data->getData()->cooldown;
}

void Tower::Upgrade(int type) {
	if(type == 1) data = data->getLeft();
	if(type == 2) data = data->getMid();
	if(type == 3) data = data->getRight();
	if(type == 4) data = data->getPrev();
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
			cool -= 1;
			transform.TurnTargetSlow(target->GetTransfromPtr()->GetPos(), 5);

			if (cool == 0) {
				Status* towerdata = data->getData();
				if (towerdata->firetype == 1) {
					Missile1* newMissile = new Missile1(GetCannonHole(towerdata), transform.GetDir(), target, data->getData()->damage);
					mainState::attacks.push_back(newMissile);
				}
				if (towerdata->firetype == 2) {
					Missile2* newMissile = new Missile2(GetCannonHole(towerdata), transform.GetDir(), target, data->getData()->damage);
					mainState::attacks.push_back(newMissile);
				}
				if(towerdata->firetype == 3) {
					Missile1* newMissile = new Missile1(GetCannonHole(towerdata), transform.GetDir(), target, 0);
					newMissile->SetSnow(std::pair<float, float>(1.0f, data->getData()->damage / 100.f));	//미사일에 1.0초 동안 유지되는 n% 둔화시키는 눈을 장착 (무한중첩됨)
					mainState::attacks.push_back(newMissile);
				}
				if (towerdata->firetype == 4) {
					Missile1* newMissile = new Missile1(GetCannonHole(towerdata), transform.GetDir(), target, 0);
					newMissile->SetPoison(std::pair<float, float>(4.0f, data->getData()->damage));	//미사일에 4.0초 동안 초당 1데미지를 주는 독을 장착 (무한중첩됨)
					mainState::attacks.push_back(newMissile);
				}
				cannonSwitch = !cannonSwitch;
				cool = towerdata->cooldown;
			}
		}
	}
}
void Tower::getNextTarget() {
	float minDistance = 10;
	glm::vec3 towerPos = transform.GetPos(); // 타워의 위치

	for (auto it = mainState::ants.begin(); it != mainState::ants.end(); it++) {
		glm::vec3 antPos = (*it)->GetTransfromPtr()->GetPos(); // 개미의 위치
		
		float distance = sqrt(pow(antPos.x - towerPos.x, 2) + pow(antPos.z - towerPos.z, 2));
		if (distance <= data->getData()->range && distance < minDistance) { // 사거리내의 가까운적
			minDistance = distance;
			target = (*it);

		}
	}
}

glm::vec3 Tower::GetCannonHole(Status* _data) {
	glm::vec3 cannonHolePos;	//포구의 높이로 생성
	if (_data->modeltype == 1) {
		cannonHolePos = glm::vec3(0, 0.4f, 0.1f);
	}
	if (_data->modeltype == 2) {
		cannonHolePos = glm::vec3(0, 0.4f, 0.4f);
		if (cannonSwitch) {	//왼쪽 포구로 발사
			cannonHolePos.x = 0.1f;
		}
		else {	//오른쪽 포구로 발사
			cannonHolePos.x = -0.1f;
		}
	}
	if (_data->modeltype == 3) {
		cannonHolePos = glm::vec3(0, 0.5f, 0.0f);
		if (cannonSwitch) {	//왼쪽 포구로 발사
			cannonHolePos.x = 0.2f;
		}
		else {	//오른쪽 포구로 발사
			cannonHolePos.x = -0.2f;
		}
	}
	//회전
	cannonHolePos = glm::rotate(glm::mat4(1.0f), atan2(transform.GetDir().x, transform.GetDir().z), glm::vec3(0, 1, 0)) * glm::vec4(cannonHolePos, 1.0f);

	cannonHolePos += transform.GetPos();	//자신의 위치로 이동

	return cannonHolePos;

}