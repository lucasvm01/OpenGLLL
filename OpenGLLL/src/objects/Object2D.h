#pragma once

#include "Object.h"

class Object2D : public Object {
	// Translation
	virtual void TranslatePositiveZ() override {}
	virtual void TranslateNegativeZ() override {}
	
	// Rotation
	virtual void RotatePositiveZ(float step) override {}
	virtual void RotateNegativeZ(float step) override {}
};