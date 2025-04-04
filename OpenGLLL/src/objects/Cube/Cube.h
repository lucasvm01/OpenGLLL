#pragma once

#include "../Object.h"

class Cube : public Object {
public:
	void SetPositionVertices(float* vertices, unsigned int* indices); // GetObject() from file?
	void DefineProperties();

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	void Move();
private:

};