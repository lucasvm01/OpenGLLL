#shader vertex
#version 410 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 tex_coord;

out vec2 v_tex_coord;

uniform mat4 u_mvp;

void MultiplyMatrixVector(glm::vec3& i, glm::vec3& o, glm::mat4x4& m)
{
	o.x = i.x * m[0][0] + i.y * m[1][0] + i.z * m[2][0] + m[3][0];
	o.y = i.x * m[0][1] + i.y * m[1][1] + i.z * m[2][1] + m[3][1];
	o.z = i.x * m[0][2] + i.y * m[1][2] + i.z * m[2][2] + m[3][2];
	float w = i.x * m[0][3] + i.y * m[1][3] + i.z * m[2][3] + m[3][3];

	if (w != 0.0f) {
		o.x /= w; o.y /= w; o.z /= w;
	}
}

void main(){
	gl_Position = u_mvp * position;

	v_tex_coord = tex_coord;
}

#shader fragment
#version 410 core

layout(location = 0) out vec4 color;

in vec2 v_tex_coord;

uniform vec4 u_color;
uniform sampler2D u_texture;

void main(){
	vec4 tex_color = texture(u_texture, v_tex_coord);

	color = tex_color;
}