#include "gameoverState.h"

float gameoverState::life = 2.0f;

GLvoid gameoverState::drawScene() //--- 콜백 함수: 그리기 콜백 함수	
{
	GLfloat rColor, gColor, bColor;

	rColor = 0.0;
	gColor = 0.0;
	bColor = 1.0;
	glClearColor(rColor, gColor, bColor, 1.0f); // 바탕색을 지정
	GLuint UIShader = GloVar::shader[0].GetShaderID();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
	glDisable(GL_DEPTH_TEST); // 은면제거용

	glUseProgram(UIShader);


	GloVar::titleScreen.Draw(GloVar::gameoverTexture);
	glEnable(GL_DEPTH_TEST); // 은면제거용
	glUseProgram(0);

	glutSwapBuffers(); // 화면에 출력하기
}



GLvoid gameoverState::Reshape(int w, int h) //--- 콜백 함수: 다시 그리기 콜백 함수 
{
	glViewport(0, 0, w, h);
}


GLvoid gameoverState::Mouse(int button, int state, int x, int y) {
	
}


GLvoid gameoverState::Keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'q':
		glutDestroyWindow(1);
		break;
	}
}

GLvoid gameoverState::sKeyboard(int key, int x, int y) {
	switch (key) {
	case GLUT_ENTERED:		
		State* newState = new startState();	//이부분 수정
		GloVar::glptr->chstate(newState);
		break;
	}
}

GLvoid gameoverState::Motion(int x, int y) {

}

GLvoid gameoverState::Update(int value) {
	life -= 1.0f / 60.0f;
	if (life <= 0) {
		//화면 돌아가기
		State* newState = new startState();	//이부분 수정
		GloVar::glptr->chstate(newState);
		return;
	}
	else {
		glutTimerFunc(16, Update, 0);
	}
}

void gameoverState::SetCallbackFunc() {
	Reshapeptr = gameoverState::Reshape;
	drawSceneptr = gameoverState::drawScene;
	sKeyboardptr = gameoverState::sKeyboard;
	Keyboardptr = gameoverState::Keyboard;
	Mouseptr = gameoverState::Mouse;
	Motionptr = gameoverState::Motion;
	Updateptr = gameoverState::Update;
	glutPostRedisplay();
}