#include "Engine.h"

Engine::Engine() {
	_shadersFactory = std::unique_ptr<ShadersFactory>(new ShadersFactory());
}

Engine::~Engine() {
	_shadersFactory.reset();

	// close GL context and any other GLFW resources
	glfwTerminate();
}

void Engine::initialize() {
	configureOpenGL();

	ShadersFactory& shadersFactory(*_shadersFactory);
	shadersFactory.loadShaders();
}

void Engine::configureOpenGL() {
	// start GL context and O/S window using the GLFW helper library
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(1);
	}

	_window = glfwCreateWindow(640, 480, "Hello Triangle", NULL, NULL);
	if (!_window) {
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		glfwTerminate();
		exit(1);
	}

	glfwMakeContextCurrent(_window);

	// Start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	// Print OpenGL version info
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	// Tell GL to only draw onto a pixel if the shape is closer to the viewer
	glEnable(GL_DEPTH_TEST); // enable depth-testing
	glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"
}

void Engine::start() {
	Triangle triangle(*this);

	while (!glfwWindowShouldClose(_window)) {
		// wipe the drawing surface clear
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Triangle draw function
		triangle.draw();
		
		// update other events like input handling 
		glfwPollEvents();
		// put the stuff we've been drawing onto the display
		glfwSwapBuffers(_window);
	}
}
