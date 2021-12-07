#include "numUI.h"
void numUI::Draw(int num, int digit) {
	myModel = &GloVar::model_numui[digit];
	texture = &GloVar::numTexture[num];
	GLuint shaderID = GloVar::shader[0].GetShaderID();
	myModel->Draw(*texture);
}