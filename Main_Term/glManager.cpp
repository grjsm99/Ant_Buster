#include "glManager.h"
#include "shader.h"
#include "startState.h"


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

	State* newState = new startState();
	pushState(newState);

	//Initbuffer();
}

void GLManager::mainLoop() {
	glutMainLoop();
}

void GLManager::pushState(State* s) {
	statelist.push_back(s);
	glutDisplayFunc(s->drawSceneptr); // 출력 함수의 지정
	glutReshapeFunc(s->Reshapeptr); // 다시 그리기 함수 지정
	glutSpecialFunc(s->sKeyboardptr); // 특수키 함수 지정
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