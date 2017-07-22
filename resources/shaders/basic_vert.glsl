#version 330 core

layout(location = 0) in vec3 vertices;
layout(location = 1) in vec3 normals;
layout(location = 2) in vec2 uvs;
layout(location = 3) in vec3 indices;

uniform mat4 MVP;
uniform mat4 M;
uniform mat4 V;


out vec3 pos;

void main() {
	
	pos = vertices;

	gl_Position = MVP * vec4(vertices, 1.0f); 
}