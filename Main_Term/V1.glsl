#version 330 core

in vec3 vPos;
in vec3 vColor;
in vec3 nPos;

out vec3 passColor;
out vec3 passNor;
out vec3 fragPos;

uniform mat4 normalTransform;
uniform mat4 modelTransform;
uniform mat4 viewTransform;
uniform mat4 projectionTransform;

void main() 
{
	gl_Position = projectionTransform * viewTransform * modelTransform * vec4(vPos, 1);	
	passColor = vColor;
	fragPos = vec3(modelTransform * vec4(vPos, 1));
	passNor = nPos;
}