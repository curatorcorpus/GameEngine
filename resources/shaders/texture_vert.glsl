#version 330 core

// These mesh positions and normals are in model space.
layout(location = 0) in vec3 vertices;
layout(location = 1) in vec3 normals;
layout(location = 2) in vec2 uvs;

uniform mat4 MVP;
uniform mat4 M;
uniform mat4 V;

uniform vec3 cam_pos;
uniform vec3 light_pos = vec3(10.0f,10.0f,10.0f);

out vec3 pos;
out vec3 norm;
out vec2 uv;
out vec3 light_dir;
out vec3 eye_dir;

void main() 
{
	pos  = vertices;
	uv   = uvs;
	norm = normals;

	// Vector that has direction from camera to vertex.
	vec3 cam_space_vert = (M*V*vec4(vertices,1.0f)).xyz;
	eye_dir = cam_pos - cam_space_vert;

	// Vector that goes from light to vertex.
	vec3 c_light_pos = (V*vec4(light_pos, 1.0f)).xyz;
	light_dir = c_light_pos + eye_dir;

	gl_Position = MVP * vec4(vertices, 1.0f);
}