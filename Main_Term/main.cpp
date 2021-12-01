#pragma region basic input
#include <iostream>
#include <stdlib.h>
#include <gl/glew.h> //--- 필요한 헤더파일 include
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "global_var.h"

#include "model_3d.h"
#include "model_maker.h"
#include "transform.h"
#include "glManager.h"
#include "shader.h"
#include "camera.h"
#pragma comment(lib, "freeglut.lib")
#pragma comment(lib, "glew32.lib")
#pragma endregion

using namespace std;


void main(int argc, char** argv) //--- 윈도우 출력하고 콜백함수 설정 { //--- 윈도우 생성하기
{
	GLManager gl(GloVar::winWidth, GloVar::winHeight, argc, argv);
	GloVar::glptr = &gl;
	GloVar::shader[0].InitShader("vertex2D.glsl", "fragment2D.glsl");
	GloVar::shader[1].InitShader("vertex1.glsl", "fragment1.glsl");
	GloVar::shader[2].InitShader("vertex_tex.glsl", "fragment_tex.glsl");
	GloVar::InitGloVar();

	gl.mainLoop();
}





