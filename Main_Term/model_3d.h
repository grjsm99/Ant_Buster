#pragma once
#include "texture.h"
#include <gl/glew.h>

class Model3D {
private:
	GLuint VAO;
	int num_Triangle;

public:
	float minX, maxX, minY, maxY, minZ, maxZ;

	void SetVAO(GLuint _VAO) { VAO = _VAO; }
	void SetNumTriangle(int _num) { num_Triangle = _num; }

	GLuint GetVAO() { return VAO; }
	GLuint* GetPVAO() { return &VAO; }

	void Draw();
	void Draw(Texture& texture);
	void Draw(int first, int _num_Triangle);
	void Draw(int first, int _num_Triangle, Texture &texture);

};