#include "selectedUI.h"

void selectedUI::click(int x, int z) {
	if (cx == x && cz == z) select = !select;
	else {
		cx = x;
		cz = z;
		transform.SetPos(glm::vec3(x - 4.5, 0.05, z - 4.5));
		select = true;
	}
}
glm::vec2 selectedUI::getIndex() {
	if (select) return glm::vec2(cx, cz);
	else return glm::vec2(-1, -1);
}

void selectedUI::Draw() {
	if (select) {
		GLuint shaderID = GloVar::shader[2].GetShaderID();

		unsigned int modelLocation = glGetUniformLocation(shaderID, "modelTransform");
		unsigned int normalLocation = glGetUniformLocation(shaderID, "normalTransform");

		//¸ðµ¨ Æ®·£½ºÆû
		glm::mat4 modelTransform = transform.GetModelMat();
		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelTransform));

		//³ë¸Ö Æ®·£½ºÆû
		glm::mat4 normalTransform = transform.GetNormalMat();
		glUniformMatrix4fv(normalLocation, 1, GL_FALSE, glm::value_ptr(normalTransform));

		myModel->Draw(*texture);
	}
}