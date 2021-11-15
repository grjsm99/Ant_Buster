#include "glManager.h"
#include "shader.h"

extern Shader shaderID;
extern Model3D m3d;
extern ModelMaker make;
float k = 0.0;

GLManager::GLManager(int winWidth, int winHeight, int argc, char** argv) {
	width = winWidth;
	height = winHeight;

	glutInit(&argc, argv); // glut 초기화
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // 디스플레이 모드 설정
	glutInitWindowPosition(0, 0); // 윈도우의 위치 지정
	glutInitWindowSize(winWidth, winHeight); // 윈도우의 크기 지정
	glutCreateWindow("Example1"); // 윈도우 생성 (윈도우 이름)
	//--- GLEW 초기화하기
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) // glew 초기화
	{
		std::cerr << "Unable to initialize GLEW" << std::endl;
		exit(EXIT_FAILURE);
	}
	else	std::cout << "GLEW Initialized\n";

	//Initbuffer();
}

void GLManager::mainLoop() {
	glutDisplayFunc(drawScene); // 출력 함수의 지정
	glutReshapeFunc(Reshape); // 다시 그리기 함수 지정
	glutSpecialFunc(sKeyboard); // 특수키 함수 지정
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(Mouse);
	glutMotionFunc(Motion);
	glutMainLoop(); // 이벤트 처리 시작 }
}


GLvoid GLManager::drawScene() //--- 콜백 함수: 그리기 콜백 함수	
{
	GLfloat rColor, gColor, bColor;

	rColor = 0.0;
	gColor = 0.0;
	bColor = 1.0;
	glClearColor(rColor, gColor, bColor, 1.0f); // 바탕색을 지정

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
	glEnable(GL_DEPTH_TEST); // 은면제거용

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
	int lightPosLocation = glGetUniformLocation(shaderID.rtsh(0), "lightPos"); //--- lightPos 값 전달: (0.0, 0.0, 5.0);
	glUniform3f(lightPosLocation, 0.0, 0.0, 2.5f);
	int lightColorLocation = glGetUniformLocation(shaderID.rtsh(0), "lightColor"); //--- lightColor 값 전달: (1.0, 1.0, 1.0) 백색
	glUniform3f(lightColorLocation, 1.0f,1.0f,1.0f);


	glm::vec3 cameraPos = glm::vec3(k, 0, 2.5f); // 카메라의 위치
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

	glutSwapBuffers(); // 화면에 출력하기
}



GLvoid GLManager::Reshape(int w, int h) //--- 콜백 함수: 다시 그리기 콜백 함수 
{
	glViewport(0, 0, w, h);
}


GLvoid GLManager::Mouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//POINTFLOAT conXY = convertGLXY(x, y);
		std::cout << "x = " << x << " y = " <<  y << std::endl;
		std::cout << "사각형 클릭!!" << std::endl;
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


