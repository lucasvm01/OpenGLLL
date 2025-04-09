#pragma once

#include "glllm/linear_algebra.h"

struct Triangle {
	glm::vec3 v1;
	glm::vec3 v2;
	glm::vec3 v3;
		  
	glm::vec3 GetNormal(){
		return glllm::normalize(glllm::cross(v1, v2));
	}
};
