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
	static Texture gameoverTexture;
	static Texture bgTexture;
	static Texture GroundTexture;
	static Texture AntNestTexture;
	static Texture CakeTexture;
	static Texture MainUITexture;
	static Texture selectedTexture;
	static Texture numTexture[10];
	static Texture tInfoTexture[20];
	static Texture turretTexture[20];

	static Texture AntTexture;
	static Texture AntSnowingTexture;
	static Texture AntPoisoningTexture;

	static Texture basicturretTexture;
	static Texture iceturretTexture;
	static Texture _2turretTexture;
	static Texture _4turretTexture;

	static Texture missile1Texture;
	static Texture missile2Texture;

	static Model3D model_plain;
	static Model3D model_cake;
	static Model3D titleScreen;
	static Model3D model_antNest;
	static Model3D model_ant;
	static Model3D model_1turret;
	static Model3D model_2turret;
	static Model3D model_4turret;
	static Model3D model_missile1;
	static Model3D model_missile2;
	static Model3D model_selected;
	static Model3D model_towerinfo[5];
	static Model3D model_numui[3];
	
	// 모델, 텍스처, 사거리, 데미지, 공격속도 설정
	static techtree root; // 기본 타워

	static ModelMaker modelMaker;

	static void InitGloVar();

};