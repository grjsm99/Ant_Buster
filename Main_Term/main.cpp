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

void Initbuffer() {
	GloVar::modelMaker.SetTransform(glm::vec3(0, 0, 0), glm::vec3(10, 1, 10), glm::vec3(0, 0, 0));
	GloVar::modelMaker.LoadObj("sphere.obj");
	GloVar::model_plain = GloVar::modelMaker.MakeModel3D(GloVar::shader.GetShaderID(), "vPos", "vNormal");
}

void main(int argc, char** argv) //--- 윈도우 출력하고 콜백함수 설정 { //--- 윈도우 생성하기
{
	GLManager gl(GloVar::winWidth, GloVar::winHeight, argc, argv);
	GloVar::glptr = &gl;
	GloVar::shader.InitShader("vertex1.glsl", "fragment1.glsl");

	Initbuffer();
	GloVar::InitGloVar();

	gl.mainLoop();
}





