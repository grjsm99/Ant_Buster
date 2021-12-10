#pragma once
#include "model_3d.h"
#include "global_var.h"

class techUI : public Object
{
	Model3D* myModel[5];
	Texture* texture[5];
	bool flag[5];
public:
	techUI();
	void InitTexture(techtree*);
	void Draw();
};