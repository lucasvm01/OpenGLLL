#pragma once

#include "../Object.h"

class Square : public Object {
public:
	void SetPositionVertices(glm::vec3* vertices, unsigned int* indices); // GetObject() from file?
	void DefineProperties(std::string shader_path, std::string texture_path);

	void MovementUp();
	void MovementDown();
	void MovementLeft();
	void MovementRight();
	
	void Move();
private:

};