#pragma once
#include "model_maker.h"
#include "model_3d.h"
#include "glManager.h"
#include "shader.h"

class GloVar {
public:
	static int winHeight;
	static int  winWidth;

	static Shader shader[3];

	static GLManager* glptr;

	static Texture TitleTexture;
	static Texture GroundTexture;

	static Model3D model_plain;
	static Model3D titleScreen;
	static ModelMaker modelMaker;

	static void InitGloVar();

};