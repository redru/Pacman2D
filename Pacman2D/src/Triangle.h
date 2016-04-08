#pragma once
#include <iostream>

#include "Engine.h"
#include "Entity.h"
#include "ShadersFactory.h"

class Triangle : public Entity {

public:
	Triangle(Engine& engine);
	~Triangle();

	void draw();

private:
	GLuint vao, vbo;

	static const float* _vertices;

};