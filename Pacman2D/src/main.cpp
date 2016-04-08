#include <iostream>
#include <memory>

#include "Engine.h"

int main(void) {
	Engine engine;

	// Initialize OpenGL engine context
	engine.initialize();

	// Run the engine main loop
	engine.start();

	return 0;
}
