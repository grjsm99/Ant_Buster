#include "model_3d.h"

//3D��
void Model3D::Draw() {
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, num_Triangle);
}
void Model3D::Draw(int _num_Triangle) {
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, _num_Triangle);
}