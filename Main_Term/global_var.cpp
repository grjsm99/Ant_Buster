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
Texture GloVar::AntSnowingTexture;
Texture GloVar::AntPoisoningTexture;
Texture GloVar::CakeTexture;


Texture GloVar::basicturretTexture;
Texture GloVar::iceturretTexture;
Texture GloVar::_2turretTexture;
Texture GloVar::_4turretTexture;
Texture GloVar::turretTexture[20];


Texture GloVar::missile1Texture;
Texture GloVar::missile2Texture;
Texture GloVar::MainUITexture;
Texture GloVar::selectedTexture;
Texture GloVar::numTexture[10];
Texture GloVar::tInfoTexture[20];

techtree GloVar::root(&GloVar::model_1turret, &GloVar::turretTexture[0], 6, 5, 1000, 5, tInfoTexture[0], 1, 1);

Model3D GloVar::titleScreen;
Model3D GloVar::model_plain;
Model3D GloVar::model_cake;
Model3D GloVar::model_antNest;
Model3D GloVar::model_ant;
Model3D GloVar::model_1turret;
Model3D GloVar::model_2turret;
Model3D GloVar::model_4turret;
Model3D GloVar::model_missile1;
Model3D GloVar::model_missile2;
Model3D GloVar::model_selected;
Model3D GloVar::model_numui[3];
Model3D GloVar::model_towerinfo[5];

ModelMaker GloVar::modelMaker;

void GloVar::InitGloVar() {
	GloVar::modelMaker.SetTransform(glm::vec3(90.0f, 0, 0), glm::vec3(2, 2, 2), glm::vec3(0, 0, 0));
	GloVar::modelMaker.LoadObj("plain.obj");
	GloVar::titleScreen = GloVar::modelMaker.MakeModel3D(GloVar::shader[0].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::TitleTexture.InitTexture(GloVar::shader[0].GetShaderID(), "title.png", "outTexture");
	GloVar::bgTexture.InitTexture(GloVar::shader[0].GetShaderID(), "bg.jpg", "outTexture");
	GloVar::MainUITexture.InitTexture(GloVar::shader[0].GetShaderID(), "mainui.bmp", "outTexture");


	
	// 타워 정보

	GloVar::modelMaker.SetTransform(glm::vec3(90.0f, 0, 0), glm::vec3(0.4, 0.15, 0.6), glm::vec3(-0.45, 0.5, -0.2));
	GloVar::modelMaker.LoadObj("plain.obj");
	GloVar::model_towerinfo[0] = GloVar::modelMaker.MakeModel3D(GloVar::shader[0].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::modelMaker.SetTransform(glm::vec3(90.0f, 0, 0), glm::vec3(0.4, 0.15, 0.6), glm::vec3(-0.7, -0.2, -0.2));
	GloVar::modelMaker.LoadObj("plain.obj");
	GloVar::model_towerinfo[1] = GloVar::modelMaker.MakeModel3D(GloVar::shader[0].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::modelMaker.SetTransform(glm::vec3(90.0f, 0, 0), glm::vec3(0.4, 0.15, 0.6), glm::vec3(-0.25, -0.2, -0.2));
	GloVar::modelMaker.LoadObj("plain.obj");
	GloVar::model_towerinfo[2] = GloVar::modelMaker.MakeModel3D(GloVar::shader[0].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::modelMaker.SetTransform(glm::vec3(90.0f, 0, 0), glm::vec3(0.4, 0.15, 0.6), glm::vec3(0.2, -0.2, -0.2));
	GloVar::modelMaker.LoadObj("plain.obj");
	GloVar::model_towerinfo[3] = GloVar::modelMaker.MakeModel3D(GloVar::shader[0].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::modelMaker.SetTransform(glm::vec3(90.0f, 0, 0), glm::vec3(0.4, 0.15, 0.6), glm::vec3(0.3, 0.5, -0.2));
	GloVar::modelMaker.LoadObj("plain.obj");
	GloVar::model_towerinfo[4] = GloVar::modelMaker.MakeModel3D(GloVar::shader[0].GetShaderID(), "vPos", "vNormal", "tPos");

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
	GloVar::AntSnowingTexture.InitTexture(GloVar::shader[2].GetShaderID(), "ant3d_snowing.jpg", "outTexture");
	GloVar::AntPoisoningTexture.InitTexture(GloVar::shader[2].GetShaderID(), "ant3d_poisoning.jpg", "outTexture");

	//터렛
	GloVar::modelMaker.SetTransform(glm::vec3(0, 180, 0), glm::vec3(1, 1, 1), glm::vec3(0, 0.3, 0.0));
	GloVar::modelMaker.LoadObj("1turret.obj");
	GloVar::model_1turret = GloVar::modelMaker.MakeModel3D(GloVar::shader[2].GetShaderID(), "vPos", "vNormal", "tPos");

	GloVar::modelMaker.SetTransform(glm::vec3(0, -90, 0), glm::vec3(1, 1, 1), glm::vec3(0, 0.4, 0.15));
	GloVar::modelMaker.LoadObj("2turret.obj");
	GloVar::model_2turret = GloVar::modelMaker.MakeModel3D(GloVar::shader[2].GetShaderID(), "vPos", "vNormal", "tPos");

	GloVar::modelMaker.SetTransform(glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), glm::vec3(0, 0.4, 0.0));
	GloVar::modelMaker.LoadObj("4turret.obj");
	GloVar::model_4turret = GloVar::modelMaker.MakeModel3D(GloVar::shader[2].GetShaderID(), "vPos", "vNormal", "tPos");

	GloVar::turretTexture[0].InitTexture(GloVar::shader[2].GetShaderID(), "ttex100.bmp", "outTexture");
	GloVar::turretTexture[1].InitTexture(GloVar::shader[2].GetShaderID(), "ttex110.bmp", "outTexture");
	GloVar::turretTexture[2].InitTexture(GloVar::shader[2].GetShaderID(), "ttex111.bmp", "outTexture");
	GloVar::turretTexture[3].InitTexture(GloVar::shader[2].GetShaderID(), "ttex112.bmp", "outTexture");
	GloVar::turretTexture[4].InitTexture(GloVar::shader[2].GetShaderID(), "ttex120.bmp", "outTexture");
	GloVar::turretTexture[5].InitTexture(GloVar::shader[2].GetShaderID(), "ttex121.bmp", "outTexture");
	GloVar::turretTexture[6].InitTexture(GloVar::shader[2].GetShaderID(), "ttex122.bmp", "outTexture");
	GloVar::turretTexture[7].InitTexture(GloVar::shader[2].GetShaderID(), "ttex130.bmp", "outTexture");
	GloVar::turretTexture[8].InitTexture(GloVar::shader[2].GetShaderID(), "ttex131.bmp", "outTexture");
	GloVar::turretTexture[9].InitTexture(GloVar::shader[2].GetShaderID(), "ttex132.bmp", "outTexture");
	GloVar::turretTexture[10].InitTexture(GloVar::shader[2].GetShaderID(), "ttex133.bmp", "outTexture");
	GloVar::turretTexture[11].InitTexture(GloVar::shader[2].GetShaderID(), "ttex1111.bmp", "outTexture");
	GloVar::turretTexture[12].InitTexture(GloVar::shader[2].GetShaderID(), "ttex1121.bmp", "outTexture");
	GloVar::turretTexture[13].InitTexture(GloVar::shader[2].GetShaderID(), "ttex1211.bmp", "outTexture");
	GloVar::turretTexture[14].InitTexture(GloVar::shader[2].GetShaderID(), "ttex1221.bmp", "outTexture");
	GloVar::turretTexture[15].InitTexture(GloVar::shader[2].GetShaderID(), "ttex1321.bmp", "outTexture");
	GloVar::turretTexture[16].InitTexture(GloVar::shader[2].GetShaderID(), "ttex1331.bmp", "outTexture");
	GloVar::turretTexture[17].InitTexture(GloVar::shader[2].GetShaderID(), "ttex13311.bmp", "outTexture");

	GloVar::tInfoTexture[0].InitTexture(GloVar::shader[0].GetShaderID(), "Tower100.bmp", "outTexture");
	GloVar::tInfoTexture[1].InitTexture(GloVar::shader[0].GetShaderID(), "Tower110.bmp", "outTexture");
	GloVar::tInfoTexture[2].InitTexture(GloVar::shader[0].GetShaderID(), "Tower111.bmp", "outTexture");
	GloVar::tInfoTexture[3].InitTexture(GloVar::shader[0].GetShaderID(), "Tower112.bmp", "outTexture");
	GloVar::tInfoTexture[4].InitTexture(GloVar::shader[0].GetShaderID(), "Tower120.bmp", "outTexture");
	GloVar::tInfoTexture[5].InitTexture(GloVar::shader[0].GetShaderID(), "Tower121.bmp", "outTexture");
	GloVar::tInfoTexture[6].InitTexture(GloVar::shader[0].GetShaderID(), "Tower122.bmp", "outTexture");
	GloVar::tInfoTexture[7].InitTexture(GloVar::shader[0].GetShaderID(), "Tower130.bmp", "outTexture");
	GloVar::tInfoTexture[8].InitTexture(GloVar::shader[0].GetShaderID(), "Tower131.bmp", "outTexture");
	GloVar::tInfoTexture[9].InitTexture(GloVar::shader[0].GetShaderID(), "Tower132.bmp", "outTexture");
	GloVar::tInfoTexture[10].InitTexture(GloVar::shader[0].GetShaderID(), "Tower133.bmp", "outTexture");
	GloVar::tInfoTexture[11].InitTexture(GloVar::shader[0].GetShaderID(), "Tower1111.bmp", "outTexture");
	GloVar::tInfoTexture[12].InitTexture(GloVar::shader[0].GetShaderID(), "Tower1121.bmp", "outTexture");
	GloVar::tInfoTexture[13].InitTexture(GloVar::shader[0].GetShaderID(), "Tower1211.bmp", "outTexture");
	GloVar::tInfoTexture[14].InitTexture(GloVar::shader[0].GetShaderID(), "Tower1221.bmp", "outTexture");
	GloVar::tInfoTexture[15].InitTexture(GloVar::shader[0].GetShaderID(), "Tower1321.bmp", "outTexture");
	GloVar::tInfoTexture[16].InitTexture(GloVar::shader[0].GetShaderID(), "Tower1331.bmp", "outTexture");
	GloVar::tInfoTexture[17].InitTexture(GloVar::shader[0].GetShaderID(), "Tower13311.bmp", "outTexture");

	// 사거리, 데미지, 쿨타임, 가격 . 1 = 기본탄 2 = 로켓탄 3 = 얼음(둔화) 4 = 독(도트데미지)
	// 1 = 1터렛, 2 = 2터렛, 3 = 3터렛
	// 래피드 타워트리
	techtree* rapidturret1 = new techtree(&GloVar::model_1turret, &GloVar::turretTexture[1], 6, 4, 500, 8, tInfoTexture[1], 1, 1);
	root.setLeft(rapidturret1);
	techtree* rapidturret2 = new techtree(&GloVar::model_1turret, &GloVar::turretTexture[2], 6, 4, 250, 12, tInfoTexture[2], 1, 1);
	rapidturret1->setLeft(rapidturret2);
	techtree* rapidturret3 = new techtree(&GloVar::model_1turret, &GloVar::turretTexture[11], 7, 6, 143, 30, tInfoTexture[11], 1, 1);
	rapidturret2->setLeft(rapidturret3);

	techtree* iceturret1 = new techtree(&GloVar::model_1turret, &GloVar::turretTexture[3], 2, 40, 500, 35, tInfoTexture[3], 3, 1);
	rapidturret1->setMid(iceturret1);
	techtree* iceturret2 = new techtree(&GloVar::model_1turret, &GloVar::turretTexture[12], 2, 70, 500, 35, tInfoTexture[12], 3, 1);
	iceturret1->setLeft(iceturret2);

	// 헤비 타워트리
	techtree* heavyturret1 = new techtree(&GloVar::model_1turret, &GloVar::turretTexture[4], 6, 7, 1000, 5, tInfoTexture[4], 1, 1);
	root.setMid(heavyturret1);

	techtree* heavyturret2 = new techtree(&GloVar::model_1turret, &GloVar::turretTexture[5], 6, 19, 1000, 15, tInfoTexture[5], 1, 1);
	heavyturret1->setLeft(heavyturret2);

	techtree* heavyturret3 = new techtree(&GloVar::model_1turret, &GloVar::turretTexture[13], 7, 98, 1000, 70, tInfoTexture[13], 1, 1);
	heavyturret2->setLeft(heavyturret3);

	techtree* rocketturret1 = new techtree(&GloVar::model_4turret, &GloVar::turretTexture[6], 8, 35, 1500, 18, tInfoTexture[6], 2, 3);
	heavyturret1->setMid(rocketturret1);

	techtree* rocketturret2 = new techtree(&GloVar::model_4turret, &GloVar::turretTexture[14], 10, 127, 2000, 45, tInfoTexture[14], 2, 3);
	rocketturret1->setLeft(rocketturret2);

	// 더블 타워트리
	techtree* doubleturret1 = new techtree(&GloVar::model_2turret, &GloVar::turretTexture[7], 4, 6, 500, 9, tInfoTexture[7], 1, 2);
	root.setRight(doubleturret1);

	techtree* heavydouble = new techtree(&GloVar::model_2turret, &GloVar::turretTexture[8], 4, 18, 500, 21, tInfoTexture[8], 1, 2);
	doubleturret1->setLeft(heavydouble);

	techtree* poisonturret1 = new techtree(&GloVar::model_2turret, &GloVar::turretTexture[9], 2, 5, 200, 40, tInfoTexture[9], 4, 2);
	doubleturret1->setMid(poisonturret1);

	techtree* poisonturret2 = new techtree(&GloVar::model_2turret, &GloVar::turretTexture[15], 2, 9, 200, 40, tInfoTexture[15], 4, 2);
	poisonturret1->setLeft(poisonturret2);

	techtree* rapiddouble1 = new techtree(&GloVar::model_2turret, &GloVar::turretTexture[10], 7, 6, 250, 19, tInfoTexture[10], 1, 2);
	doubleturret1->setRight(rapiddouble1);

	techtree* rapiddouble2 = new techtree(&GloVar::model_2turret, &GloVar::turretTexture[16], 8, 9, 200, 34, tInfoTexture[16], 1, 2);
	rapiddouble1->setLeft(rapiddouble2);

	techtree* rapiddouble3 = new techtree(&GloVar::model_2turret, &GloVar::turretTexture[17], 9, 37, 125, 142, tInfoTexture[17], 1, 2);
	rapiddouble2->setLeft(rapiddouble3);

	//미사일1
	GloVar::modelMaker.SetTransform(glm::vec3(0, 180, 0), glm::vec3(0.5, 0.5, 0.5), glm::vec3(0, 0, 0));
	GloVar::modelMaker.LoadObj("missile1_3d.obj");
	GloVar::model_missile1 = GloVar::modelMaker.MakeModel3D(GloVar::shader[2].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::missile1Texture.InitTexture(GloVar::shader[2].GetShaderID(), "missile1_3d.bmp", "outTexture");

	//미사일2
	GloVar::modelMaker.SetTransform(glm::vec3(0, 90, 0), glm::vec3(0.5, 0.5, 0.5), glm::vec3(0, 0, 0));
	GloVar::modelMaker.LoadObj("missile2_3d.obj");
	GloVar::model_missile2 = GloVar::modelMaker.MakeModel3D(GloVar::shader[2].GetShaderID(), "vPos", "vNormal", "tPos");
	GloVar::missile2Texture.InitTexture(GloVar::shader[2].GetShaderID(), "missile2_3d.jpg", "outTexture");

	
}
