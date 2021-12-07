#include "mainState.h"
#include <string.h>
Camera mainState::camera;
Light mainState::sun;
Plain mainState::plain;
AntNest mainState::antNest;
int mainState::gold;
selectedUI mainState::selected;

std::vector<Ant*> mainState::ants;
std::vector<Tower*> mainState::towers;
std::vector<Attack*> mainState::attacks;
std::vector<cake*> mainState::cakeList;

glm::vec3 mainState::attLights[200];

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
		//std::cout << "x = " << x << " y = " << y << std::endl;
	//std::cout << "�簢�� Ŭ��!!" << std::endl;
		float m22 = std::atan(45.0f / 2.0f);
		float m11 = m22 / ((float)GloVar::winWidth / (float)GloVar::winHeight);

		glm::vec3 start = camera.Eye();
		//std::cout << "cam x = " << start.x << " y = " << start.y << " z = " << start.z << std::endl;
		//std::cout << "cam x = " << camera.At().x << " y = " << camera.At().y << " z = " << camera.At().z << std::endl;
		glm::vec4 ray(((2.0f * (float)x / (float)GloVar::winWidth) - 1.0f) / m11, ((-2.0f * (float)(y + 177) / (float)GloVar::winHeight) + 1.0f) / m22, -1.0f, 0);
		glm::mat4 viewInverse(1.0f);
		viewInverse = glm::transpose(glm::lookAt(camera.Eye(), camera.At(), camera.Up()));

		ray = viewInverse * ray;
		//std::cout << "ray x = " << ray.x << " y = " << ray.y << " z = " << ray.z << std::endl;
		float t = (0.0f - start.y) / ray.y;
		float rx = start.x + t * ray.x;
		float rz = start.z + t * ray.z - 5.0f;
		rx = rx;
		rz = rz * 10.0f / 6.2f;
		//std::cout << "t = " << t << " x = " << rx << " z = " << rz << std::endl;
		//std::cout << "�簢�� Ŭ��!!" << std::endl;
		rx = (int)(rx + 5);
		rz = (int)(rz + 5);
		std::cout << (int)(rx + 5) << ", " << (int)(rz + 5) << std::endl;
		if (rx >= 0 && rx <= 9 && rz >= 0 && rz <= 9) {
			selected.click(rx, rz);
		}
	}
}

GLvoid mainState::Motion(int x, int y) {
	//POINTFLOAT conXY = convertGLXY(x, y);
	

}

GLvoid mainState::Keyboard(unsigned char key, int x, int y) {
	switch (key) {
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