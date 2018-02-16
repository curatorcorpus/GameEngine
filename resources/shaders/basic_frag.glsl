#version 330 core

in vec3 pos;
in vec2 uv;

out vec4 color;

uniform sampler2D texture2D;

void main() 
{
	color = texture(texture2D, uv) * vec4(1.0f,1.0f,1.0f, 1.0f);
};