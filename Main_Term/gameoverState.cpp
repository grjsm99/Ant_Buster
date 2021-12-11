#include "gameoverState.h"

float gameoverState::life = 2.0f;

GLvoid gameoverState::drawScene() //--- �ݹ� �Լ�: �׸��� �ݹ� �Լ�	
{
	GLfloat rColor, gColor, bColor;

	rColor = 0.0;
	gColor = 0.0;
	bColor = 1.0;
	glClearColor(rColor, gColor, bColor, 1.0f); // �������� ����
	GLuint UIShader = GloVar::shader[0].GetShaderID();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
	glDisable(GL_DEPTH_TEST); // �������ſ�

	glUseProgram(UIShader);


	GloVar::titleScreen.Draw(GloVar::gameoverTexture);
	glEnable(GL_DEPTH_TEST); // �������ſ�
	glUseProgram(0);

	glutSwapBuffers(); // ȭ�鿡 ����ϱ�
}



GLvoid gameoverState::Reshape(int w, int h) //--- �ݹ� �Լ�: �ٽ� �׸��� �ݹ� �Լ� 
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
		State* newState = new startState();	//�̺κ� ����
		GloVar::glptr->chstate(newState);
		break;
	}
}

GLvoid gameoverState::Motion(int x, int y) {

}

GLvoid gameoverState::Update(int value) {
	life -= 1.0f / 60.0f;
	if (life <= 0) {
		//ȭ�� ���ư���
		State* newState = new startState();	//�̺κ� ����
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