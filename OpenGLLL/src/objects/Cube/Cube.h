#pragma once

#include "../Object.h"


class Cube : public Object {
public:
	// Setup
	void SetPositionVertices(glm::vec3* vertices, unsigned int* indices) override; // GetObject() from file?
	void DefineProperties() override;

	void Move() override;
};