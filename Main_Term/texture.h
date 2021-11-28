#pragma once
#include <gl/glew.h>
#include <string>
#include "stb_image.h"


class Texture {
private:
	unsigned int texture;

public:
	Texture();

	void InitTexture(GLuint _shaderID, std::string fileName, std::string samplerName);
	void BindTexture();
};