#version 330 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vNormal;
layout (location = 2) in vec2 tPos;

out vec3 FragPos; //--- ��ü�� ��ġ���� �����׸�Ʈ ���̴��� ������.
out vec3 Normal; //--- ��ְ��� �����׸�Ʈ ���̴��� ������.
out vec2 TexCoord;


uniform mat4 normalTransform;
uniform mat4 modelTransform; //--- �𵨸� ��ȯ��
uniform mat4 viewTransform; //--- ���� ��ȯ��
uniform mat4 projectionTransform; //--- ���� ��ȯ��

void main()
{
	gl_Position = projectionTransform * viewTransform * modelTransform * vec4(vPos, 1.0);
	FragPos = vec3(modelTransform * vec4(vPos, 1.0));
	Normal = vec3( normalTransform * vec4(vNormal, 1.0) );
	TexCoord = tPos;
}

