#include "global_var.h"

int GloVar::winHeight = 800;
int GloVar::winWidth = 1200;

Shader GloVar::shader[3];

GLManager* GloVar::glptr;

Texture GloVar::TitleTexture;
Texture GloVar::bgTexture;
Texture GloVar::GroundTexture;
Texture GloVar::AntNestTexture;
Texture GloVar::AntTexture;
Texture GloVar::CakeTexture;
Texture GloVar::basicturretTexture;
Texture GloVar::iceturretTexture;
Texture GloVar::missile1Texture;
Texture GloVar::MainUITexture;
Texture GloVar::selectedTexture;
Texture GloVar::numTexture[10];

techtree GloVar::root(&GloVar::model_turret, &GloVar::basicturretTexture, 6, 5, 500);

Model3D GloVar::titleScreen;
Model3D GloVar::model_plain;
Model3D GloVar::model_cake;
Model3D GloVar::model_antNest;
Model3D GloVar::model_ant;
Model3D GloVar::model_turret;
Model3D GloVar::model_missile1;
Model3D GloVar::model_selected;
Model3D GloVar::model_numui[3];

ModelMaker GloVar::modelMaker;

void GloVar::InitGloVar() {
	GloVar::modelMaker.SetTransform(glm::vec3(90.0f, 0, 0), glm::vec3(2, 2, 2), glm::vec3(0, 0, 0));
	GloVar::modelMaker.LoadObj("plain.obj");
	GloVar::titleScreen = GloVar::modelMaker.MakeModel3D(GloVar::shader[0].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::TitleTexture.InitTexture(GloVar::shader[0].GetShaderID(), "title.png", "outTexture");
	GloVar::bgTexture.InitTexture(GloVar::shader[0].GetShaderID(), "bg.jpg", "outTexture");
	GloVar::MainUITexture.InitTexture(GloVar::shader[0].GetShaderID(), "mainui.bmp", "outTexture");


	// 숫자



	GloVar::modelMaker.SetTransform(glm::vec3(90.0f, 0, 0), glm::vec3(0.1, 0.15, 0.5), glm::vec3(0.85, -0.4, -0.2));
	GloVar::modelMaker.LoadObj("plain.obj");
	GloVar::model_numui[0] = GloVar::modelMaker.MakeModel3D(GloVar::shader[0].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::modelMaker.SetTransform(glm::vec3(90.0f, 0, 0), glm::vec3(0.1, 0.15, 0.5), glm::vec3(0.75, -0.4, -0.2));
	GloVar::modelMaker.LoadObj("plain.obj");
	GloVar::model_numui[1] = GloVar::modelMaker.MakeModel3D(GloVar::shader[0].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::modelMaker.SetTransform(glm::vec3(90.0f, 0, 0), glm::vec3(0.1, 0.15, 0.5), glm::vec3(0.65, -0.4, -0.2));
	GloVar::modelMaker.LoadObj("plain.obj");
	GloVar::model_numui[2] = GloVar::modelMaker.MakeModel3D(GloVar::shader[0].GetShaderID(), "vPos", "vNormal", "tPos");

	GloVar::numTexture[0].InitTexture(GloVar::shader[0].GetShaderID(), "Num0.bmp", "outTexture");
	GloVar::numTexture[1].InitTexture(GloVar::shader[0].GetShaderID(), "Num1.bmp", "outTexture");
	GloVar::numTexture[2].InitTexture(GloVar::shader[0].GetShaderID(), "Num2.bmp", "outTexture");
	GloVar::numTexture[3].InitTexture(GloVar::shader[0].GetShaderID(), "Num3.bmp", "outTexture");
	GloVar::numTexture[4].InitTexture(GloVar::shader[0].GetShaderID(), "Num4.bmp", "outTexture");
	GloVar::numTexture[5].InitTexture(GloVar::shader[0].GetShaderID(), "Num5.bmp", "outTexture");
	GloVar::numTexture[6].InitTexture(GloVar::shader[0].GetShaderID(), "Num6.bmp", "outTexture");
	GloVar::numTexture[7].InitTexture(GloVar::shader[0].GetShaderID(), "Num7.bmp", "outTexture");
	GloVar::numTexture[8].InitTexture(GloVar::shader[0].GetShaderID(), "Num8.bmp", "outTexture");
	GloVar::numTexture[9].InitTexture(GloVar::shader[0].GetShaderID(), "Num9.bmp", "outTexture");



	//땅바닥
	GloVar::modelMaker.SetTransform(glm::vec3(0, 0, 0), glm::vec3(10, 1, 10), glm::vec3(0, 0, 0));
	GloVar::modelMaker.LoadObj("plain.obj");
	GloVar::model_plain = GloVar::modelMaker.MakeModel3D(GloVar::shader[2].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::GroundTexture.InitTexture(GloVar::shader[2].GetShaderID(), "gr.jpg", "outTexture");

	// 선택 표시
	GloVar::modelMaker.SetTransform(glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), glm::vec3(0, 0, 0));
	GloVar::modelMaker.LoadObj("plain.obj");
	GloVar::model_selected = GloVar::modelMaker.MakeModel3D(GloVar::shader[2].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::selectedTexture.InitTexture(GloVar::shader[2].GetShaderID(), "selected.jpg", "outTexture");

	// 케이크
	GloVar::modelMaker.SetTransform(glm::vec3(0, -45, 0), glm::vec3(1,1,1), glm::vec3(0, 0.1, -0.2));
	GloVar::modelMaker.LoadObj("cake.obj");
	GloVar::model_cake = GloVar::modelMaker.MakeModel3D(GloVar::shader[2].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::CakeTexture.InitTexture(GloVar::shader[2].GetShaderID(), "cake_n.jpg", "outTexture");
	//개미집
	GloVar::modelMaker.SetTransform(glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), glm::vec3(0, 0.1, 0));
	GloVar::modelMaker.LoadObj("antNest.obj");
	GloVar::model_antNest = GloVar::modelMaker.MakeModel3D(GloVar::shader[2].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::AntNestTexture.InitTexture(GloVar::shader[2].GetShaderID(), "antNest.bmp", "outTexture");

	//개미
	GloVar::modelMaker.SetTransform(glm::vec3(-90, 90, 0), glm::vec3(1, 1, 1), glm::vec3(0, 0.2, 0));
	GloVar::modelMaker.LoadObj("ant3d.obj");
	GloVar::model_ant = GloVar::modelMaker.MakeModel3D(GloVar::shader[2].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::AntTexture.InitTexture(GloVar::shader[2].GetShaderID(), "ant3d.jpg", "outTexture");

	//터렛
	GloVar::modelMaker.SetTransform(glm::vec3(0, -90, 0), glm::vec3(1, 1, 1), glm::vec3(0, 0.4, 0.15));
	GloVar::modelMaker.LoadObj("turret.obj");
	GloVar::model_turret = GloVar::modelMaker.MakeModel3D(GloVar::shader[2].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::basicturretTexture.InitTexture(GloVar::shader[2].GetShaderID(), "turretSkin.png", "outTexture");
	GloVar::iceturretTexture.InitTexture(GloVar::shader[2].GetShaderID(), "iceturretSkin.png", "outTexture");

	techtree* iceturret = new techtree(&GloVar::model_turret, &GloVar::iceturretTexture, 6, 10, 300);
	root.setLeft(iceturret);

	//미사일1
	GloVar::modelMaker.SetTransform(glm::vec3(0, 180, 0), glm::vec3(0.5, 0.5, 0.5), glm::vec3(0, 0, 0));
	GloVar::modelMaker.LoadObj("missile1_3d.obj");
	GloVar::model_missile1 = GloVar::modelMaker.MakeModel3D(GloVar::shader[2].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::missile1Texture.InitTexture(GloVar::shader[2].GetShaderID(), "missile1_3d.bmp", "outTexture");

	
}
