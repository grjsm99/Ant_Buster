#version 330 core

in vec3 passColor;
in vec3 passNor;
in vec3 fragPos;
out vec4 fragmentColor;

uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 pColor;
uniform vec3 viewPos;
void main()
{

	float ambientLight = 0.3;
	vec3 ambient = ambientLight * lightColor;

	vec3 normalVector = normalize(passNor);
	vec3 lightDir = normalize(lightPos - fragPos);
	float diffuseLight = max(dot(normalVector, lightDir), 0.0);
	vec3 diffuse = diffuseLight * lightColor;

	int shininess = 128;
	vec3 viewDir = normalize(viewPos - fragPos);
	vec3 reflectDir = reflect(-lightDir, normalVector);
	float specularLight = max(dot(viewDir, reflectDir), 0.0);
	specularLight = pow(specularLight, shininess);
	vec3 specular = specularLight * lightColor;
	
	
	vec3 result = (ambient + diffuse + specular) * pColor;
	
	fragmentColor = vec4(result, 1.0);
}