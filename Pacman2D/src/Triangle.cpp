#include "Triangle.h"

static const float vertices[] = {
	0.0f,  0.5f,  0.0f, 1.0f,
	0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.0f, 1.0f
};

const float* Triangle::_vertices = vertices;

Triangle::Triangle(Engine& engine) : Entity(engine) {
	vbo = 0;
	vao = 0;

	glGenBuffers(1, &vbo); // Generato VBO

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), Triangle::_vertices, GL_STATIC_DRAW); // Buffer data to GPU memory using the VBO
	
	
	glGenVertexArrays(1, &vao); // Generate VAO

	glBindVertexArray(vao); // Bind VAO
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindVertexArray(0); // Unbind VAO
}

Triangle::~Triangle() {
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}

void Triangle::draw() {
	ShaderProgram& program(Entity::engine().getShadersFactory().getProgram("default"));

	glUseProgram(program.programId());
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3); // Draw points from 0 to 3 from the currently bound VAO with current in-use shader
	glBindVertexArray(0);
}
