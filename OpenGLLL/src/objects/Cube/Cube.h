#pragma once

#include "../Object.h"


class Cube : public Object {
public:
	// Setup
	void SetPositionVertices(glm::vec3* vertices, unsigned int* indices) override; // GetObject() from file?
	void DefineProperties(int op) override;

	// Rotation
	void RotationPositiveX() override;
	void RotationNegativeX() override;

	void RotationPositiveY() override;
	void RotationNegativeY() override;

	void RotationPositiveZ() override;
	void RotationNegativeZ() override;

	void Move() override;
};