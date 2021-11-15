#include "model_3d.h"
#include "model_maker.h"
#include "state.h"
#include "shader.h"
#include "glManager.h"
extern Shader shader;
extern Model3D m3d;
extern ModelMaker make;
extern GLManager* glptr;
float k = 0.0;

GLvoid mainState::drawScene() //--- �ݹ� �Լ�: �׸��� �ݹ� �Լ�	
{
	GLfloat rColor, gColor, bColor;

	rColor = 0.0;
	gColor = 0.0;
	bColor = 1.0;
	glClearColor(rColor, gColor, bColor, 1.0f); // �������� ����

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
	glEnable(GL_DEPTH_TEST); // �������ſ�

	glUseProgram(shader.rtsh());
	glm::mat4 model(1.0f);
	glm::mat4 view(1.0f);
	glm::mat4 projection(1.0f);

	unsigned int normalLoca = glGetUniformLocation(shader.rtsh(), "normalTransform");
	unsigned int modelLoca = glGetUniformLocation(shader.rtsh(), "modelTransform");
	unsigned int viewLoca = glGetUniformLocation(shader.rtsh(), "viewTransform");
	unsigned int projLoca = glGetUniformLocation(shader.rtsh(), "projectionTransform");
	std::cout << normalLoca << std::endl;
	int camPosLocation = glGetUniformLocation(shader.rtsh(), "viewPos");
	glUniform3f(camPosLocation, k, 0.0f, 2.5f);
	int lightPosLocation = glGetUniformLocation(shader.rtsh(), "lightPos"); //--- lightPos �� ����: (0.0, 0.0, 5.0);
	glUniform3f(lightPosLocation, 0.0, 0.0, 2.5f);
	int lightColorLocation = glGetUniformLocation(shader.rtsh(), "lightColor"); //--- lightColor �� ����: (1.0, 1.0, 1.0) ���
	glUniform3f(lightColorLocation, 1.0f, 1.0f, 1.0f);


	glm::vec3 cameraPos = glm::vec3(k, 0, 2.5f); // ī�޶��� ��ġ
	std::cout << k << "," << 2.5;
	glm::vec3 cameraDirection = glm::vec3(k, 0.0f, 0.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	view = glm::lookAt(cameraPos, cameraDirection, cameraUp);

	projection = glm::perspective(glm::radians(45.0f), (float)600 / (float)600, 0.1f, 100.0f);

	glUniformMatrix4fv(modelLoca, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoca, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoca, 1, GL_FALSE, glm::value_ptr(projection));


	int colPos = glGetUniformLocation(shader.rtsh(), "pColor");
	glUniform3f(colPos, 1, 0, 1);
	m3d.Draw();
	glUseProgram(0);

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
		k += 0.1;
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

GLvoid startState::drawScene() //--- �ݹ� �Լ�: �׸��� �ݹ� �Լ�	
{
	GLfloat rColor, gColor, bColor;

	rColor = 0.0;
	gColor = 0.0;
	bColor = 1.0;
	glClearColor(rColor, gColor, bColor, 1.0f); // �������� ����

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
	glEnable(GL_DEPTH_TEST); // �������ſ�

	glUseProgram(shader.rtsh());
	glm::mat4 model(1.0f);
	glm::mat4 view(1.0f);
	glm::mat4 projection(1.0f);

	unsigned int normalLoca = glGetUniformLocation(shader.rtsh(), "normalTransform");
	unsigned int modelLoca = glGetUniformLocation(shader.rtsh(), "modelTransform");
	unsigned int viewLoca = glGetUniformLocation(shader.rtsh(), "viewTransform");
	unsigned int projLoca = glGetUniformLocation(shader.rtsh(), "projectionTransform");
	std::cout << normalLoca << std::endl;
	int camPosLocation = glGetUniformLocation(shader.rtsh(), "viewPos");
	glUniform3f(camPosLocation, k, 0.0f, 2.5f);
	int lightPosLocation = glGetUniformLocation(shader.rtsh(), "lightPos"); //--- lightPos �� ����: (0.0, 0.0, 5.0);
	glUniform3f(lightPosLocation, 0.0, 0.0, 2.5f);
	int lightColorLocation = glGetUniformLocation(shader.rtsh(), "lightColor"); //--- lightColor �� ����: (1.0, 1.0, 1.0) ���
	glUniform3f(lightColorLocation, 1.0f, 1.0f, 1.0f);


	glm::vec3 cameraPos = glm::vec3(k, 0, 2.5f); // ī�޶��� ��ġ
	std::cout << k << "," << 2.5;
	glm::vec3 cameraDirection = glm::vec3(k, 0.0f, 0.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	view = glm::lookAt(cameraPos, cameraDirection, cameraUp);

	projection = glm::perspective(glm::radians(45.0f), (float)600 / (float)600, 0.1f, 100.0f);

	glUniformMatrix4fv(modelLoca, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoca, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoca, 1, GL_FALSE, glm::value_ptr(projection));


	int colPos = glGetUniformLocation(shader.rtsh(), "pColor");
	glUniform3f(colPos, 1, 1, 0);
	m3d.Draw();
	glUseProgram(0);

	glutSwapBuffers(); // ȭ�鿡 ����ϱ�
}



GLvoid startState::Reshape(int w, int h) //--- �ݹ� �Լ�: �ٽ� �׸��� �ݹ� �Լ� 
{
	glViewport(0, 0, w, h);
}


GLvoid startState::Mouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//POINTFLOAT conXY = convertGLXY(x, y);
		std::cout << "x = " << x << " y = " << y << std::endl;
		std::cout << "�簢�� Ŭ��!!" << std::endl;
	}
}


GLvoid startState::Keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'p':
	{
		State* newState = new mainState();
		glptr->chstate(newState);
		glutPostRedisplay();
		break;
	}
	case 'q':
		glutDestroyWindow(1);
		break;
	}
}

GLvoid startState::sKeyboard(int key, int x, int y) {
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

GLvoid startState::Motion(int x, int y) {

}
