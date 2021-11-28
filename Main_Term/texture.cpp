#define STB_IMAGE_IMPLEMENTATION
#include "texture.h"

Texture::Texture() {}

void Texture::InitTexture(GLuint _shaderID, std::string fileName, std::string samplerName) {

	stbi_set_flip_vertically_on_load(true);
	stbi_set_flip_vertically_on_load_thread(true);

	glGenTextures(1, &texture); //--- �ؽ�ó ����
	glBindTexture(GL_TEXTURE_2D, texture); //--- �ؽ�ó ���ε�
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); //--- ���� ���ε��� �ؽ�ó�� �Ķ���� �����ϱ�
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int widthImage, heightImage, numberOfChannel;
	unsigned char* data = stbi_load(fileName.c_str(), &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data); //---�ؽ�ó �̹��� ����

	glUseProgram(_shaderID);
	int tLocation = glGetUniformLocation(_shaderID, samplerName.c_str()); //--- outTexture ������ ���÷��� ��ġ�� ������
	glUniform1i(tLocation, 0);
}

void Texture::BindTexture() {
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
}