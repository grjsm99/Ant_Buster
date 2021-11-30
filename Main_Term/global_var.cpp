#include "global_var.h"

int GloVar::winHeight = 800;
int GloVar::winWidth = 1200;

Shader GloVar::shader[3];

GLManager* GloVar::glptr;

Texture GloVar::TitleTexture;
Texture GloVar::GroundTexture;
Texture GloVar::AntNestTexture;

Model3D GloVar::titleScreen;
Model3D GloVar::model_plain;
Model3D GloVar::model_antNest;
ModelMaker GloVar::modelMaker;

void GloVar::InitGloVar() {
	
}
