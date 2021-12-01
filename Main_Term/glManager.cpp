#include "glManager.h"
#include "shader.h"
#include "startState.h"


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

	State* newState = new startState();
	pushState(newState);

	//Initbuffer();
}

void GLManager::mainLoop() {
	glutMainLoop();
}

void GLManager::pushState(State* s) {
	statelist.push_back(s);
	glutDisplayFunc(s->drawSceneptr); // ��� �Լ��� ����
	glutReshapeFunc(s->Reshapeptr); // �ٽ� �׸��� �Լ� ����
	glutSpecialFunc(s->sKeyboardptr); // Ư��Ű �Լ� ����
	glutKeyboardFunc(s->Keyboardptr);
	glutMouseFunc(s->Mouseptr);
	glutMotionFunc(s->Motionptr);
	glutTimerFunc(16 ,s->Updateptr, 0);
}

void GLManager::chstate(State* s) {
	delete statelist.back();
	statelist.pop_back();
	pushState(s);
}