#define STB_IMAGE_IMPLEMENTATION
#include "texture.h"

Texture::Texture() {}

void Texture::InitTexture(GLuint _shaderID, std::string fileName, std::string samplerName) {

	stbi_set_flip_vertically_on_load(true);
	stbi_set_flip_vertically_on_load_thread(true);

	glGenTextures(1, &texture); //--- 텍스처 생성
	glBindTexture(GL_TEXTURE_2D, texture); //--- 텍스처 바인딩
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); //--- 현재 바인딩된 텍스처의 파라미터 설정하기
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int widthImage, heightImage, numberOfChannel;
	unsigned char* data = stbi_load(fileName.c_str(), &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data); //---텍스처 이미지 정의

	glUseProgram(_shaderID);
	int tLocation = glGetUniformLocation(_shaderID, samplerName.c_str()); //--- outTexture 유니폼 샘플러의 위치를 가져옴
	glUniform1i(tLocation, 0);
}

void Texture::BindTexture() {
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
}