#include "glManager.h"
#include "shader.h"

extern Shader shaderID;
extern Model3D m3d;
extern ModelMaker make;
float k = 0.0;

GLManager::GLManager(int winWidth, int winHeight, int argc, char** argv) {
	width = winWidth;
	height = winHeight;

	glutInit(&argc, argv); // glut �ʱ�ȭ
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // ���÷��� ��� ����
	glutInitWindowPosition(0, 0); // �������� ��ġ ����
	glutInitWindowSize(winWidth, winHeight); // �������� ũ�� ����
	glutCreateWindow("Example1"); // ������ ���� (������ �̸�)
	//--- GLEW �ʱ�ȭ�ϱ�
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) // glew �ʱ�ȭ
	{
		std::cerr << "Unable to initialize GLEW" << std::endl;
		exit(EXIT_FAILURE);
	}
	else	std::cout << "GLEW Initialized\n";

	//Initbuffer();
}

void GLManager::mainLoop() {
	glutDisplayFunc(drawScene); // ��� �Լ��� ����
	glutReshapeFunc(Reshape); // �ٽ� �׸��� �Լ� ����
	glutSpecialFunc(sKeyboard); // Ư��Ű �Լ� ����
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(Mouse);
	glutMotionFunc(Motion);
	glutMainLoop(); // �̺�Ʈ ó�� ���� }
}


GLvoid GLManager::drawScene() //--- �ݹ� �Լ�: �׸��� �ݹ� �Լ�	
{
	GLfloat rColor, gColor, bColor;

	rColor = 0.0;
	gColor = 0.0;
	bColor = 1.0;
	glClearColor(rColor, gColor, bColor, 1.0f); // �������� ����

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
	glEnable(GL_DEPTH_TEST); // �������ſ�

	glUseProgram(shaderID.rtsh(0));
	glm::mat4 model(1.0f);
	glm::mat4 view(1.0f);
	glm::mat4 projection(1.0f);

	unsigned int normalLoca = glGetUniformLocation(shaderID.rtsh(0), "normalTransform");
	unsigned int modelLoca = glGetUniformLocation(shaderID.rtsh(0), "modelTransform");
	unsigned int viewLoca = glGetUniformLocation(shaderID.rtsh(0), "viewTransform");
	unsigned int projLoca = glGetUniformLocation(shaderID.rtsh(0), "projectionTransform");
	std::cout << normalLoca << std::endl;
	int camPosLocation = glGetUniformLocation(shaderID.rtsh(0), "viewPos");
	glUniform3f(camPosLocation, k, 0.0f, 2.5f);
	int lightPosLocation = glGetUniformLocation(shaderID.rtsh(0), "lightPos"); //--- lightPos �� ����: (0.0, 0.0, 5.0);
	glUniform3f(lightPosLocation, 0.0, 0.0, 2.5f);
	int lightColorLocation = glGetUniformLocation(shaderID.rtsh(0), "lightColor"); //--- lightColor �� ����: (1.0, 1.0, 1.0) ���
	glUniform3f(lightColorLocation, 1.0f,1.0f,1.0f);


	glm::vec3 cameraPos = glm::vec3(k, 0, 2.5f); // ī�޶��� ��ġ
	std::cout << k << "," << 2.5;
	glm::vec3 cameraDirection = glm::vec3(k, 0.0f, 0.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	view = glm::lookAt(cameraPos, cameraDirection, cameraUp);

	projection = glm::perspective(glm::radians(45.0f), (float)600 / (float)600, 0.1f, 100.0f);

	glUniformMatrix4fv(modelLoca, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoca, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoca, 1, GL_FALSE, glm::value_ptr(projection));


	int colPos = glGetUniformLocation(shaderID.rtsh(0), "pColor");
	glUniform3f(colPos, 1, 0, 1);
	m3d.Draw();
	glUseProgram(0);

	glutSwapBuffers(); // ȭ�鿡 ����ϱ�
}



GLvoid GLManager::Reshape(int w, int h) //--- �ݹ� �Լ�: �ٽ� �׸��� �ݹ� �Լ� 
{
	glViewport(0, 0, w, h);
}


GLvoid GLManager::Mouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//POINTFLOAT conXY = convertGLXY(x, y);
		std::cout << "x = " << x << " y = " <<  y << std::endl;
		std::cout << "�簢�� Ŭ��!!" << std::endl;
	}
}


GLvoid GLManager::Keyboard(unsigned char key, int x, int y) {
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

GLvoid GLManager::sKeyboard(int key, int x, int y) {
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

GLvoid GLManager::Motion(int x, int y) {

}


