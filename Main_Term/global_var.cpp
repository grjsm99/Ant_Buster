#include "global_var.h"

int GloVar::winHeight = 800;
int GloVar::winWidth = 1200;

Shader GloVar::shader[3];

GLManager* GloVar::glptr;

Texture GloVar::TitleTexture;
Texture GloVar::GroundTexture;
Texture GloVar::AntNestTexture;
Texture GloVar::AntTexture;
Texture GloVar::basicturretTexture;
Texture GloVar::iceturretTexture;
Texture GloVar::missile1Texture;


techtree GloVar::root(&GloVar::model_turret, &GloVar::basicturretTexture, 6, 5, 10);

Model3D GloVar::titleScreen;
Model3D GloVar::model_plain;
Model3D GloVar::model_antNest;
Model3D GloVar::model_ant;
Model3D GloVar::model_turret;
Model3D GloVar::model_missile1;
ModelMaker GloVar::modelMaker;

void GloVar::InitGloVar() {
	GloVar::modelMaker.SetTransform(glm::vec3(90.0f, 0, 0), glm::vec3(2, 2, 2), glm::vec3(0, 0, 0));
	GloVar::modelMaker.LoadObj("plain.obj");
	GloVar::titleScreen = GloVar::modelMaker.MakeModel3D(GloVar::shader[0].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::TitleTexture.InitTexture(GloVar::shader[0].GetShaderID(), "title.png", "outTexture");

	//¶¥¹Ù´Ú
	GloVar::modelMaker.SetTransform(glm::vec3(0, 0, 0), glm::vec3(10, 1, 10), glm::vec3(0, 0, 0));
	GloVar::modelMaker.LoadObj("plain.obj");
	GloVar::model_plain = GloVar::modelMaker.MakeModel3D(GloVar::shader[2].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::GroundTexture.InitTexture(GloVar::shader[2].GetShaderID(), "ground.jpg", "outTexture");

	//°³¹ÌÁý
	GloVar::modelMaker.SetTransform(glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), glm::vec3(0, 0.1, 0));
	GloVar::modelMaker.LoadObj("antNest.obj");
	GloVar::model_antNest = GloVar::modelMaker.MakeModel3D(GloVar::shader[2].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::AntNestTexture.InitTexture(GloVar::shader[2].GetShaderID(), "antNest.bmp", "outTexture");

	//°³¹Ì
	GloVar::modelMaker.SetTransform(glm::vec3(-90, 90, 0), glm::vec3(1, 1, 1), glm::vec3(0, 0.2, 0));
	GloVar::modelMaker.LoadObj("ant3d.obj");
	GloVar::model_ant = GloVar::modelMaker.MakeModel3D(GloVar::shader[2].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::AntTexture.InitTexture(GloVar::shader[2].GetShaderID(), "ant3d.jpg", "outTexture");

	//ÅÍ·¿
	GloVar::modelMaker.SetTransform(glm::vec3(0, -90, 0), glm::vec3(1, 1, 1), glm::vec3(0, 0.4, 0.15));
	GloVar::modelMaker.LoadObj("turret.obj");
	GloVar::model_turret = GloVar::modelMaker.MakeModel3D(GloVar::shader[2].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::basicturretTexture.InitTexture(GloVar::shader[2].GetShaderID(), "turretSkin.png", "outTexture");
	GloVar::iceturretTexture.InitTexture(GloVar::shader[2].GetShaderID(), "iceturretSkin.png", "outTexture");

	techtree* iceturret = new techtree(&GloVar::model_turret, &GloVar::iceturretTexture, 6, 10, 10);
	root.setLeft(iceturret);

	//¹Ì»çÀÏ1
	GloVar::modelMaker.SetTransform(glm::vec3(0, 180, 0), glm::vec3(0.5, 0.5, 0.5), glm::vec3(0, 0, 0));
	GloVar::modelMaker.LoadObj("missile1_3d.obj");
	GloVar::model_missile1 = GloVar::modelMaker.MakeModel3D(GloVar::shader[2].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::missile1Texture.InitTexture(GloVar::shader[2].GetShaderID(), "missile1_3d.bmp", "outTexture");

}
