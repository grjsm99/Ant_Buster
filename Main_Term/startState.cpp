#include "startState.h"

GLvoid startState::drawScene() //--- 콜백 함수: 그리기 콜백 함수	
{
	GLfloat rColor, gColor, bColor;

	rColor = 0.0;
	gColor = 0.0;
	bColor = 1.0;
	glClearColor(rColor, gColor, bColor, 1.0f); // 바탕색을 지정
	GLuint UIShader = GloVar::shader[0].GetShaderID();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
	glEnable(GL_DEPTH_TEST); // 은면제거용

	glUseProgram(UIShader);


	GloVar::titleScreen.Draw(GloVar::TitleTexture);

	glUseProgram(0);

	glutSwapBuffers(); // 화면에 출력하기
}



GLvoid startState::Reshape(int w, int h) //--- 콜백 함수: 다시 그리기 콜백 함수 
{
	glViewport(0, 0, w, h);
}


GLvoid startState::Mouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//POINTFLOAT conXY = convertGLXY(x, y);
		std::cout << "x = " << x << " y = " << y << std::endl;
		std::cout << "사각형 클릭!!" << std::endl;
	}
}


GLvoid startState::Keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'p':
	{
		State* newState = new mainState();
		GloVar::glptr->chstate(newState);
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



void startState::SetCallbackFunc() {
	Reshapeptr = startState::Reshape;
	drawSceneptr = startState::drawScene;
	sKeyboardptr = startState::sKeyboard;
	Keyboardptr = startState::Keyboard;
	Mouseptr = startState::Mouse;
	Motionptr = startState::Motion;
}