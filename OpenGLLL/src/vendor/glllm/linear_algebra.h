#pragma once

#include <glm/ext/vector_float3.hpp>
#include <glm/ext/matrix_float4x4.hpp>

namespace glllm {
	glm::vec3 cross(glm::vec3 v1, glm::vec3 v2) {
		float x = v1.y * v2.z - v1.z * v2.y;
		float y = v1.z * v2.x - v1.x * v2.z;
		float z = v1.x * v2.y - v1.y * v2.x;
		
		return glm::vec3(x, y, z);
	}

	float magnitude(glm::vec3 v) {
			return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	}

	glm::vec3 normalize(glm::vec3 v) {
		float mag = magnitude(v);
		return glm::vec3(v.x / mag, v.y / mag, v.z / mag);
	}

	glm::vec3 mult_matrix3_vec3(glm::vec3 v, glm::mat3 m) {
		float px = v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2];
		float py = v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2];
		float pz = v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2];
		float pw = v.x * m[3][0] + v.y * m[3][1] + v.z * m[3][2];

		return glm::vec3(px, py, pz);
	}

	glm::vec3 mult_matrix4_vec3(glm::mat4 m, glm::vec3 v) {
		float px = v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2] + m[0][3];
		float py = v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2] + m[1][3];
		float pz = v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2] + m[2][3];
		float pw = v.x * m[3][0] + v.y * m[3][1] + v.z * m[3][2] + m[3][3];
		
		if (pw != 0) {
			px /= pw;
			py /= pw;
			pz /= pw;
		}

		return glm::vec3(px, py, pz);
	}
}
