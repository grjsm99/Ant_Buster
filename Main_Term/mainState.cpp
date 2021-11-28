#include "mainState.h"

Camera mainState::camera;
Light mainState::sun;
Plain mainState::plain;

GLvoid mainState::drawScene() //--- �ݹ� �Լ�: �׸��� �ݹ� �Լ�	
{
	GLuint shaderID = GloVar::shader[1].GetShaderID();

	GLfloat rColor, gColor, bColor;

	rColor = 0.0;
	gColor = 0.0;
	bColor = 0.0;
	glClearColor(rColor, gColor, bColor, 1.0f); // �������� ����

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
	glEnable(GL_DEPTH_TEST); // �������ſ�

	glUseProgram(shaderID);	//�⺻ ���̴� Ȱ��ȭ
	glViewport(0, 0, GloVar::winWidth, GloVar::winHeight);	//�� ������ �׸��ڴ�.

	//���� ��ȯ
	glm::mat4 projection(1.0f);
	projection = glm::perspective(glm::radians(45.0f), (float)GloVar::winWidth / (float)GloVar::winHeight, 0.1f, 100.0f);
	unsigned int projLoca = glGetUniformLocation(shaderID, "projectionTransform");
	glUniformMatrix4fv(projLoca, 1, GL_FALSE, glm::value_ptr(projection));

	//�� ��ȯ
	glm::mat4 view(1.0f);
	view = glm::lookAt(camera.Eye(), camera.At(), camera.Up());
	unsigned int viewLoca = glGetUniformLocation(shaderID, "viewTransform");
	glUniformMatrix4fv(viewLoca, 1, GL_FALSE, glm::value_ptr(view));

	//����
	int lightPosLocation = glGetUniformLocation(shaderID, "lightPos"); //--- lightPos �� ����: (0.0, 0.0, 5.0);
	glUniform3f(lightPosLocation, sun.GetTransfromPtr()->GetPos().x, sun.GetTransfromPtr()->GetPos().y, sun.GetTransfromPtr()->GetPos().z);
	int lightColorLocation = glGetUniformLocation(shaderID, "lightColor"); //--- lightColor �� ����: (1.0, 1.0, 1.0) ���
	glUniform3f(lightColorLocation, sun.GetColor().r, sun.GetColor().g, sun.GetColor().b);
	int camPosLocation = glGetUniformLocation(shaderID, "viewPos");
	glUniform3f(camPosLocation, camera.Eye().x, camera.Eye().y, camera.Eye().z);

	
	//�ٴ� �׸���
	plain.Draw();


	glutSwapBuffers(); // ȭ�鿡 ����ϱ�
}


GLvoid mainState::Reshape(int w, int h) //--- �ݹ� �Լ�: �ٽ� �׸��� �ݹ� �Լ� 
{
	glViewport(0, 0, w, h);
}


GLvoid mainState::Mouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//POINTFLOAT conXY = convertGLXY(x, y);
		std::cout << "x = " << x << " y = " << y << std::endl;
		std::cout << "�簢�� Ŭ��!!" << std::endl;
	}
}


GLvoid mainState::Keyboard(unsigned char key, int x, int y) {
	switch (key) {
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

GLvoid mainState::Motion(int x, int y) {

}





void mainState::SetCallbackFunc() {
	Reshapeptr = mainState::Reshape;
	drawSceneptr = mainState::drawScene;
	sKeyboardptr = mainState::sKeyboard;
	Keyboardptr = mainState::Keyboard;
	Mouseptr = mainState::Mouse;
	Motionptr = mainState::Motion;
}