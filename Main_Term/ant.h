#include "model_3d.h"
#include "global_var.h"

class Ant : public Object {
	Model3D* myModel = &GloVar::model_ant;
	Texture* texture = &GloVar::AntTexture;
	float hp = 100;
	float speed = 0.01f;
public:
	Ant();

	void Draw();
	void Update();
};