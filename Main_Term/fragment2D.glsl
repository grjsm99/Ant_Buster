#version 330 core

in vec2 TexCoord;
out vec4 fragmentColor;

uniform sampler2D outTexture;

void main()
{
	fragmentColor = texture(outTexture, TexCoord);
}