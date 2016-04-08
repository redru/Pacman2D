#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "FileStreams.h"
#include "ShaderProgram.h"

class ShadersFactory {

public:
	ShadersFactory();
	~ShadersFactory();

	void loadShaders();

	// Getters - Setters
	inline ShaderProgram getProgram(std::string alias) { return _programs.find(alias)->second; }

private:
	std::map<std::string, ShaderProgram> _programs;

	ShaderProgram createProgram(std::string vertexShaderFile, std::string fragmentShaderFile, std::string programName, std::vector<std::string> uniforms);
		
};
