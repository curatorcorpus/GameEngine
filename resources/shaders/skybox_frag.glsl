#version 330 core

in vec3 texture_coords;

out vec4 color;

uniform samplerCube cubemap;

void main() 
{
	color = vec4(1.0f);//texture(cubemap, texture_coords);
};