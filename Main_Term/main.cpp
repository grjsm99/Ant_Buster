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
#include <random>
#include <list>
#pragma comment(lib, "freeglut.lib")
#pragma comment(lib, "glew32.lib")
#pragma endregion

Model3D m3d;
ModelMaker make;
Shader shaderID;
GLint width, height;

#define winHeight 600
#define winWidth 600
using namespace std;

void Initbuffer() {
	make.LoadObj("sphere.obj");
	m3d = make.MakeModel3D(shaderID.rtsh(0), "vPos", "nPos");
}


void main(int argc, char** argv) //--- 윈도우 출력하고 콜백함수 설정 { //--- 윈도우 생성하기
{
	GLManager gl(600, 600, argc, argv);
	shaderID.InitShader("V1.glsl", "F1.glsl");
	Initbuffer();
	gl.mainLoop();
}





