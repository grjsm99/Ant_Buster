#include "model_3d.h"
#include "global_var.h"

class Plain : public Object {
	Model3D* myModel = &GloVar::model_plain;
	Texture* texture = &GloVar::GroundTexture;
public:
	void Draw();

};