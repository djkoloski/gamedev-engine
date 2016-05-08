#version 330

in vec2 texCoord0;

out vec4 color;

uniform sampler2D texMap;

void main()
{
	color = texture(texMap, texCoord0);
}