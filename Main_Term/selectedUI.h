#pragma once
#include "model_3d.h"
#include "global_var.h"

class selectedUI : public Object
{
	Model3D* myModel = &GloVar::model_selected;
	Texture* texture = &GloVar::selectedTexture;
	bool select = false;
	int cx;
	int cz;
public:

	void click(int, int);
	void Draw();

};

