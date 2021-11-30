#include "model_3d.h"
#include "global_var.h"

class AntNest : public Object {
	Model3D* myModel = &GloVar::model_antNest;
	Texture* texture = &GloVar::AntNestTexture;
public:
	void Draw();

};