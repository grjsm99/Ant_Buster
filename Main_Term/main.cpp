#pragma region basic input
#include <iostream>
#include <stdlib.h>
#include <gl/glew.h> //--- 필요한 헤더파일 include
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "model_3d.h"
#include "model_maker.h"
#include "transform.h"
#include "glManager.h"
#include "shader.h"
#include "camera.h"
#pragma comment(lib, "freeglut.lib")
#pragma comment(lib, "glew32.lib")
#pragma endregion


#define winHeight 600
#define winWidth 600
using namespace std;

Model3D m3d;
ModelMaker make;

Shader shader;
GLManager* glptr;
//Camera startState::cam = Camera();
Camera mainState::cam = Camera();
std::vector<Transform*> mainState::objlist;

void Initbuffer() {
	make.LoadObj("sphere.obj");
	m3d = make.MakeModel3D(shader.rtsh(), "vPos", "nPos");
}

void main(int argc, char** argv) //--- 윈도우 출력하고 콜백함수 설정 { //--- 윈도우 생성하기
{
	GLManager gl(winWidth, winHeight, argc, argv);
	glptr = &gl;
	shader.InitShader("V1.glsl", "F1.glsl");
	Initbuffer();
	gl.mainLoop();
}





