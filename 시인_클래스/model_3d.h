#pragma once
#include <gl/glew.h>

class Model3D {
private:
	GLuint VAO;
	int num_Triangle;

public:
	int minX, maxX, minY, maxY, minZ, maxZ;

	void SetVAO(GLuint _VAO) { VAO = _VAO; }
	void SetNumTriangle(int _num) { num_Triangle = _num; }

	GLuint GetVAO() { return VAO; }
	GLuint* GetPVAO() { return &VAO; }

	void Draw();
	void Draw(int _num_Triangle);

};