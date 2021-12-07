#pragma once
#include "model_maker.h"
#include "model_3d.h"
#include "glManager.h"
#include "shader.h"
#include <map>
#include "techtree.h"

class GloVar {
public:
	static int winHeight;
	static int  winWidth;

	static Shader shader[3];

	static GLManager* glptr;

	static Texture TitleTexture;
	static Texture bgTexture;
	static Texture GroundTexture;
	static Texture AntNestTexture;
	static Texture CakeTexture;
	static Texture MainUITexture;
	static Texture selectedTexture;

	static Texture AntTexture;

	static Texture basicturretTexture;
	static Texture iceturretTexture;
	static Texture missile1Texture;

	static Model3D model_plain;
	static Model3D model_cake;
	static Model3D titleScreen;
	static Model3D model_antNest;
	static Model3D model_ant;
	static Model3D model_turret;
	static Model3D model_missile1;
	static Model3D model_selected;
	
	// 모델, 텍스처, 사거리, 데미지, 공격속도 설정
	static techtree root; // 기본 타워

	static ModelMaker modelMaker;

	static void InitGloVar();

};