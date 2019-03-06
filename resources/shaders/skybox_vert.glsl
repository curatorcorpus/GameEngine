#version 330 core

layout(location = 0) in vec3 vertices;
out vec3 texture_coords;

uniform mat4 V;
uniform mat4 P;

void main() 
{
	texture_coords = vertices;
	gl_Position = P * V * vec4(vertices, 1.0f);
}