#pragma once
#include "model_3d.h"
#include "global_var.h"

class cake : public Object 
{
	Model3D* myModel = &GloVar::model_cake;
	Texture* texture = &GloVar::CakeTexture;
public:
	cake();
	void Draw();

};

