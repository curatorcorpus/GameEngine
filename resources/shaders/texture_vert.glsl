#version 330 core

// These mesh positions and normals are in model space.
layout(location = 0) in vec3 vertices;
layout(location = 1) in vec3 normals;
layout(location = 2) in vec2 uvs;

uniform mat4 MVP;
uniform mat4 M;
uniform mat4 V;

out vec3 pos;
out vec3 norm;
out vec2 uv;

void main() 
{
	pos  = vertices;
	uv   = uvs;
	norm = normalize(M*V*vec4(normals,0.0f)).xyz;

	vec3 cam_space_vert = (M*V*vec4(vertices,1.0f)).xyz;

	gl_Position = MVP * vec4(vertices, 1.0f);
}