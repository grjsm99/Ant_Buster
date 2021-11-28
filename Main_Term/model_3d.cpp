#include "model_3d.h"

//3D¸ðµ¨
void Model3D::Draw() {
	glBindVertexArray(VAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glDrawArrays(GL_TRIANGLES, 0, num_Triangle);
}
void Model3D::Draw(Texture& texture) {
	glBindVertexArray(VAO);
	texture.BindTexture();
	glDrawArrays(GL_TRIANGLES, 0, num_Triangle);
}
void Model3D::Draw(int first, int _num_Triangle) {
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, first, _num_Triangle);
}
void Model3D::Draw(int first, int _num_Triangle, Texture &texture) {
	glBindVertexArray(VAO);
	texture.BindTexture();
	glDrawArrays(GL_TRIANGLES, first, _num_Triangle);
}