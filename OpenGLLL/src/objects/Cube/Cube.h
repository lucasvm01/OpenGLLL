#pragma once

#include "../Object.h"

class Cube : public Object {
public:
	void SetPositionVertices(glm::vec3* vertices, unsigned int* indices); // GetObject() from file?
	void DefineProperties(int op);

	void MovementUp();
	void MovementDown();
	void MovementLeft();
	void MovementRight();

	void Move();

};