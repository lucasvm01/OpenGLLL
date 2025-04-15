#pragma once

#include "Object.h"

class Object2D : public Object {
	virtual void MovementPositiveZ() override {}
	virtual void MovementNegativeZ() override {}
	
	// Rotation
	virtual void RotationPositiveX() override {}
	virtual void RotationNegativeX() override {}

	virtual void RotationPositiveY() override {}
	virtual void RotationNegativeY() override {}

	virtual void RotationPositiveZ() override {}
	virtual void RotationNegativeZ() override {}
};