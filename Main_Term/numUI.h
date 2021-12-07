#pragma once

#include "model_3d.h"
#include "global_var.h"

class numUI : public Object
{
	Model3D* myModel = &GloVar::model_numui[0];
	Texture* texture = &GloVar::numTexture[0];

public:
	void Draw(int num, int digit);
};

