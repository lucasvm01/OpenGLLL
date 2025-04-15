#pragma once

#include "../Object2D.h"

class Square : public Object2D {
public:
	void SetPositionVertices(glm::vec3* vertices, unsigned int* indices) override; // GetObject() from file?
	void DefineProperties(int op) override;

	void Move() override;
private:

};