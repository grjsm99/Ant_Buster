#include "ant_nest.h"

void AntNest::Draw() {
	GLuint shaderID = GloVar::shader[2].GetShaderID();

	unsigned int modelLocation = glGetUniformLocation(shaderID, "modelTransform");
	unsigned int normalLocation = glGetUniformLocation(shaderID, "normalTransform");

	//¸ðµ¨ Æ®·£½ºÆû
	glm::mat4 modelTransform = transfrom.GetModelMat();
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelTransform));

	//³ë¸Ö Æ®·£½ºÆû
	glm::mat4 normalTransform = transfrom.GetNormalMat();
	glUniformMatrix4fv(normalLocation, 1, GL_FALSE, glm::value_ptr(normalTransform));

	myModel->Draw(*texture);

	std::cout << "Ãâ·Â";
}