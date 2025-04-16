#pragma once

#include "Object.h"

class Object2D : public Object {
	// Translation
	virtual void TranslatePositiveZ() override {}
	virtual void TranslateNegativeZ() override {}
	
	// Rotation
	virtual void RotatePositiveZ() override {}
	virtual void RotateNegativeZ() override {}
};