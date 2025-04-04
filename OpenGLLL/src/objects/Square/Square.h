#pragma once

#include "../Object.h"

class Square : public Object {
public:
	void SetPositionVertices(glm::vec3* vertices, unsigned int* indices); // GetObject() from file?
	void DefineProperties();

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	
	void Move();
private:

};