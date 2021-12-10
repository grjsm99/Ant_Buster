#include "mainState.h"
#include <string.h>
Camera mainState::camera;
Light mainState::sun;
Plain mainState::plain;
AntNest mainState::antNest;
int mainState::gold = 993;
selectedUI mainState::selected;
numUI mainState::numui;
techUI mainState::techui;
Tower* mainState::selecttower;
bool mainState::isselect = false;
char mainState::groundIndex[10][10]{0,}; // 0 = �Ǽ��Ұ�, 1 = �Ǽ����� 2 = Ÿ�� ���� 

std::vector<Ant*> mainState::ants;
std::vector<Tower*> mainState::towers;
std::vector<Attack*> mainState::attacks;
std::vector<cake*> mainState::cakeList;
glm::vec3 mainState::attLights[200];

float rx;
float rz;

GLvoid mainState::drawScene() //--- �ݹ� �Լ�: �׸��� �ݹ� �Լ�	
{
	GLuint UIshader = GloVar::shader[0].GetShaderID();
	GLuint Colshader = GloVar::shader[1].GetShaderID();
	GLuint Texshader = GloVar::shader[2].GetShaderID();

	GLfloat rColor, gColor, bColor;

	rColor = 0.0;
	gColor = 0.0;
	bColor = 0.0;
	glClearColor(rColor, gColor, bColor, 1.0f); // �������� ����

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
	glDisable(GL_DEPTH_TEST); // �������ſ�


	
	glUseProgram(UIshader);

	glViewport(0, 350, GloVar::winWidth, GloVar::winHeight - 350);	// ���ȭ�� �׸���
	GloVar::titleScreen.Draw(GloVar::bgTexture);

	glEnable(GL_DEPTH_TEST); // �������ſ�

	glViewport(0, 0, GloVar::winWidth, 350);	// UI �׸���
	
	int money = gold;
	int digit = 0;
	while (1) {

		numui.Draw(money % 10, digit);
		if (money / 10 == 0) break;
		money = money / 10;
		digit++;

	}
	if (groundIndex[(int)rz][(int)rx] == 2 && isselect) techui.Draw();

	GloVar::titleScreen.Draw(GloVar::MainUITexture);

	glUseProgram(0);



	glViewport(0, 0, GloVar::winWidth, GloVar::winHeight);	//�� ������ �׸��ڴ�.
	glUseProgram(Texshader);	// �ؽ�ó �ִ� ��ü �׸���
	glm::mat4 projection(1.0f);
	projection = glm::perspective(glm::radians(45.0f), (float)GloVar::winWidth / (float)GloVar::winHeight, 0.1f, 200.0f);
	glm::mat4 view(1.0f);
	view = glm::lookAt(camera.Eye(), camera.At(), camera.Up());


	
	//���� ��ȯ	
	unsigned int projLoca = glGetUniformLocation(Texshader, "projectionTransform");
	glUniformMatrix4fv(projLoca, 1, GL_FALSE, glm::value_ptr(projection));

	//�� ��ȯ
	unsigned int viewLoca = glGetUniformLocation(Texshader, "viewTransform");
	glUniformMatrix4fv(viewLoca, 1, GL_FALSE, glm::value_ptr(view));

	//����
	int lightPosLocation = glGetUniformLocation(Texshader, "lightPos"); //--- lightPos �� ����: (0.0, 0.0, 5.0);
	glUniform3f(lightPosLocation, sun.GetTransfromPtr()->GetPos().x, sun.GetTransfromPtr()->GetPos().y, sun.GetTransfromPtr()->GetPos().z);

	int lightNum = attacks.size();
	int attLightsNumLocation = glGetUniformLocation(Texshader, "attLightsNum"); //--- lightPos �� ����: (0.0, 0.0, 5.0);
	glUniform1i(attLightsNumLocation, lightNum);

	for (int i = 0; i < lightNum; i++) { // ���� ����ŭ ���̴��� ���� ������
		std::string num = std::to_string(i);
		glUniform3f(glGetUniformLocation(Texshader, ("attLights[" + num + "]").c_str()), attLights[i].x, attLights[i].y, attLights[i].z);
	}
	int lightColorLocation = glGetUniformLocation(Texshader, "lightColor"); //--- lightColor �� ����: (1.0, 1.0, 1.0) ���
	glUniform3f(lightColorLocation, sun.GetColor().r, sun.GetColor().g, sun.GetColor().b);
	int camPosLocation = glGetUniformLocation(Texshader, "viewPos");
	glUniform3f(camPosLocation, camera.Eye().x, camera.Eye().y, camera.Eye().z);
	
	//�ٴ� �׸���
	plain.Draw();
	
	//������ �׸���
	antNest.Draw();

	for (int i = 0; i < cakeList.size(); ++i) {
		cakeList[i]->Draw();
	}

	//���� �׸���
	for (int i = 0; i < ants.size(); ++i) {
		ants[i]->Draw();
	}

	// Ÿ�� �׸���
	for (int i = 0; i < towers.size(); ++i) {
		towers[i]->Draw();
	}

	// ���� �׸���
	for (int i = 0; i < attacks.size(); ++i) {
		attacks[i]->Draw();
	}

	selected.Draw();
	glUseProgram(Colshader);	// �ؽ�ó ���� ��ü �׸���

		//���� ��ȯ	
	projLoca = glGetUniformLocation(Colshader, "projectionTransform");
	glUniformMatrix4fv(projLoca, 1, GL_FALSE, glm::value_ptr(projection));

	//�� ��ȯ
	viewLoca = glGetUniformLocation(Colshader, "viewTransform");
	glUniformMatrix4fv(viewLoca, 1, GL_FALSE, glm::value_ptr(view));

	//����
	lightPosLocation = glGetUniformLocation(Colshader, "lightPos"); //--- lightPos �� ����: (0.0, 0.0, 5.0);
	glUniform3f(lightPosLocation, sun.GetTransfromPtr()->GetPos().x, sun.GetTransfromPtr()->GetPos().y, sun.GetTransfromPtr()->GetPos().z);
	lightColorLocation = glGetUniformLocation(Colshader, "lightColor"); //--- lightColor �� ����: (1.0, 1.0, 1.0) ���
	glUniform3f(lightColorLocation, sun.GetColor().r, sun.GetColor().g, sun.GetColor().b);
	camPosLocation = glGetUniformLocation(Colshader, "viewPos");
	glUniform3f(camPosLocation, camera.Eye().x, camera.Eye().y, camera.Eye().z);


	glutSwapBuffers(); // ȭ�鿡 ����ϱ�
}


GLvoid mainState::Reshape(int w, int h) //--- �ݹ� �Լ�: �ٽ� �׸��� �ݹ� �Լ� 
{
	glViewport(0, 0, w, h);
}


GLvoid mainState::Mouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (y > -0.5) { // ui�� Ŭ����
			//std::cout << "x = " << x << " y = " << y << std::endl;
		//std::cout << "�簢�� Ŭ��!!" << std::endl;
			float m22 = 1.0f / std::tan(glm::radians(45.0f / 2.0f));
			float m11 = m22 / ((float)GloVar::winWidth / (float)GloVar::winHeight);

			glm::vec3 start = camera.Eye();
			glm::vec4 ray(((2.0f * (float)x / (float)GloVar::winWidth) - 1.0f) / m11, ((-2.0f * (float)y / (float)GloVar::winHeight) + 1.0f) / m22, -1.0f, 0);
			glm::mat4 viewInverse(1.0f);
			viewInverse = glm::transpose(glm::lookAt(camera.Eye(), camera.At(), camera.Up()));

			ray = viewInverse * ray;
			float t = (0.0f - start.y) / ray.y;
			rx = start.x + t * ray.x;
			rz = start.z + t * ray.z;
			rx = rx;
			rz = rz;
			std::cout << "t = " << t << " x = " << rx << " z = " << rz << std::endl;
			std::cout << "�簢�� Ŭ��!!" << std::endl;
			rx = (int)(rx + 5);
			rz = (int)(rz + 5);

			if (rx >= 0 && rx <= 9 && rz >= 0 && rz <= 9) {
				if (groundIndex[(int)rz][(int)rx] != 0) {
					selected.click(rx, rz);
					isselect = selected.getSelect();
					if (groundIndex[(int)rz][(int)rx] == 2) {
						for (auto it = mainState::towers.begin(); it != mainState::towers.end(); it++) {
							if ((*it)->towerIndex().x == rx && (*it)->towerIndex().y == rz) {
								selecttower = *it;
								break;
							}
						}
						techui.InitTexture(selecttower->getTechTree());

					}
				}
			}
		}
	}
}

GLvoid mainState::Motion(int x, int y) {
	//POINTFLOAT conXY = convertGLXY(x, y);
	

}

GLvoid mainState::Keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '1':
	{
		techtree* left = selecttower->getTechTree()->getLeft();
		if (groundIndex[(int)rz][(int)rx] == 2 && left != NULL) {
			if (gold >= left->getData()->cost) {
				gold -= left->getData()->cost;
				selecttower->Upgrade(1);
				techui.InitTexture(selecttower->getTechTree());
			}
		}
		break;
	}
	case '2':
	{
		techtree* mid = selecttower->getTechTree()->getMid();
		if (groundIndex[(int)rz][(int)rx] == 2 && mid != NULL) {
			if (gold >= mid->getData()->cost) {
				gold -= mid->getData()->cost;
				selecttower->Upgrade(2);
				techui.InitTexture(selecttower->getTechTree());
			}
		}
		break;
	}
	case '3':
	{
		techtree* right = selecttower->getTechTree()->getRight();
		if (groundIndex[(int)rz][(int)rx] == 2 && right != NULL) {
			if (gold >= right->getData()->cost) {
				gold -= right->getData()->cost;
				selecttower->Upgrade(3);
				techui.InitTexture(selecttower->getTechTree());
			}
		}
		break;
	}
	case '4':
	{
		techtree* prev = selecttower->getTechTree()->getPrev();
		if (groundIndex[(int)rz][(int)rx] == 2 && prev != NULL) {
			gold += selecttower->getTechTree()->getData()->cost / 2;
			selecttower->Upgrade(4);
			techui.InitTexture(selecttower->getTechTree());
			
		}
		break;
	}
	case 't':
		glm::vec2 selectIndex = selected.getIndex();
		if (groundIndex[(int)selectIndex.y][(int)selectIndex.x] == 1 && gold >= 10) {
			groundIndex[(int)selectIndex.y][(int)selectIndex.x] = 2;
			Tower* t = new Tower(selectIndex.x, selectIndex.y);
			//t->Upgrade(1);
			techui.InitTexture(t->getTechTree());
			towers.push_back(t);
			selecttower = t;
			gold -= 10;
		}
		break;
	case 'y':
		cakeList.pop_back();
		break;
	case 'n':
		sun.SetColor(0.2, 0.2, 0.2);
		break;
	case 'm':
		sun.SetColor(1, 1, 1);
		break;
	case 'p':
		glutPostRedisplay();
		break;
	case 'q':
		glutDestroyWindow(1);
		break;
	}
}

GLvoid mainState::sKeyboard(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:

		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:

		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:

		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:

		glutPostRedisplay();
		break;
	}
}



GLvoid mainState::Update(int value) {
	//������ ������Ʈ
	antNest.Update();

	// Ÿ�� ������Ʈ
	for (int i = 0; i < towers.size(); ++i) {
		towers[i]->Update();
	}

	// ���� ������Ʈ
	for (int i = 0; i < attacks.size(); ++i) {
		if (i == 200) break;
		attLights[i] = attacks[i]->GetTransfromPtr()->GetPos();
		attacks[i]->Update();
	}

	// ���� ������Ʈ
	for (int i = 0; i < ants.size(); ++i) {
		if (ants[i]->Update()) {
			if (cakeList.size() > 0) cakeList.pop_back();
		}
	}
	
	glutPostRedisplay();
	glutTimerFunc(16, Update, 0);
}

void mainState::SetCallbackFunc() {
	Reshapeptr = mainState::Reshape;
	drawSceneptr = mainState::drawScene;
	sKeyboardptr = mainState::sKeyboard;
	Keyboardptr = mainState::Keyboard;
	Mouseptr = mainState::Mouse;
	Motionptr = mainState::Motion;
	Updateptr = mainState::Update;
}
