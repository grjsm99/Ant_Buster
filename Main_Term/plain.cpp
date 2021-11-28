#include "plain.h"

void Plain::Draw() {
	GLuint shaderID = GloVar::shader[1].GetShaderID();

	unsigned int modelLocation = glGetUniformLocation(shaderID, "modelTransform");
	int objColorLocation = glGetUniformLocation(shaderID, "objectColor");
	unsigned int normalLocation = glGetUniformLocation(shaderID, "normalTransform");

	glUniform3f(objColorLocation, 1.0f, 1.0f, 1.0f);	//������Ʈ ����

	//�� Ʈ������
	glm::mat4 modelTransform = transfrom.GetModelMat();
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelTransform));

	//��� Ʈ������
	glm::mat4 normalTransform = transfrom.GetNormalMat();
	glUniformMatrix4fv(normalLocation, 1, GL_FALSE, glm::value_ptr(normalTransform));

	myModel->Draw();

	std::cout << "���";
}