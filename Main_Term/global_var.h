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
	static Texture GroundTexture;
	static Texture AntNestTexture;
	static Texture AntTexture;
	static Texture turretTexture;

	static Model3D model_plain;
	static Model3D titleScreen;
	static Model3D model_antNest;
	static Model3D model_ant;
	static Model3D model_turret;
	
	// ��, �ؽ�ó, ��Ÿ�, ������, ���ݼӵ� ����
	static techtree root; // �⺻ Ÿ��

	static ModelMaker modelMaker;

	static void InitGloVar();

};