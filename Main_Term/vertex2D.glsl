#version 330 core

in vec3 vPos;
in vec3 vNormal;
in vec2 tPos;

out vec2 TexCoord;

void main() 
{
	
	gl_Position = vec4(vPos, 1);	
	TexCoord = tPos;
}