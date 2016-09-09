# version 430 core

smooth in vec3 vLightDir;
smooth in vec3 normal_ES;
smooth in vec2 texCoord;

out vec4 color;

uniform sampler2D tex;

uniform vec4 lightColor;
uniform vec4 diffuseColor;
uniform vec4 ambientColor;

void main()
{
	vec4 diffuse, specular, ambient;

	vec3 normal = normalize(normal_ES);

	float diff = max(0.0f, dot(normal, vLightDir));
	diffuse = diff * diffuseColor;

	vec3 reflectionv = reflect(-vLightDir, normal);
	float reflectAngle = max(0.0f, dot(normal, normalize(reflectionv)));
	float specFactor = pow(reflectAngle, 128);
	specular = specFactor * lightColor;

	vec4 texcolor = texture(tex, texCoord);

	color = 0.000001*specular + 0.000001*diffuse + 0.000001*ambientColor + texcolor;
}