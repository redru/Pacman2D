#pragma once
#include <iostream>
#include <map>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class ShaderProgram {

public:
	ShaderProgram(GLuint vs = 0, GLuint fs = 0, GLuint program = 0, std::string programName = "none") : 
		_vs(vs), _fs(fs), _program(program), _programName(programName) {}

	~ShaderProgram() {}

	inline void vsId(GLuint vs) { _vs = vs; }
	inline GLuint vsId() { return _vs; }

	inline void fsId(GLuint fs) { _fs = fs; }
	inline GLuint fsId() { return _fs; }

	inline void programId(GLuint program) { _program = program; }
	inline GLuint programId() { return _program; }

	inline void programName(GLuint programName) { _programName = programName; }
	inline std::string programName() { return _programName; }

	inline void uniform(std::string uniformId, GLuint value) { _uniforms.insert(std::pair<std::string, GLuint>(uniformId, value)); }
	inline GLuint uniform(std::string uniformId) { return _uniforms.find(uniformId)->second; }

private:
	GLuint _vs, _fs, _program;
	std::string _programName;
	std::map<std::string, GLuint> _uniforms;

};
