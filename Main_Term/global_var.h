#pragma once
#include "model_maker.h"
#include "model_3d.h"
#include "glManager.h"
#include "shader.h"

class GloVar {
public:
	static int winHeight;
	static int  winWidth;

	static Shader shader;

	static GLManager* glptr;

	static Model3D model_plain;
	static ModelMaker modelMaker;

	static void InitGloVar();

};