#pragma once
#include <iostream>
#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Entity.h"
#include "ShadersFactory.h"
#include "Triangle.h"

class Engine {

public:
	// Constructor - Destructor
	Engine();
	~Engine();

	// Function used to initialize the engine components
	void initialize();

	// Function that starts the engine main loop
	void start();

	// Getters
	inline ShadersFactory& getShadersFactory() { return *_shadersFactory; }
	inline GLFWwindow* window() { return _window; }

private:
	GLFWwindow* _window;
	std::unique_ptr<ShadersFactory> _shadersFactory;

	void configureOpenGL();

};
