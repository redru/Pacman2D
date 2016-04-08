#include "ShadersFactory.h"

ShadersFactory::ShadersFactory() {

}

ShadersFactory::~ShadersFactory() {

}

void ShadersFactory::loadShaders() {
	std::cout << "Loading and compiling shaders..." << std::endl;
	ShaderProgram defaultProgram = createProgram("assets\\shaders\\vs_default_v_140.glsl", "assets\\shaders\\fs_default_v_140.glsl", "default", std::vector<std::string>{ "u_mvpMatrix" });
	_programs.insert(std::pair<std::string, ShaderProgram>(defaultProgram.programName(), defaultProgram));
}

ShaderProgram ShadersFactory::createProgram(
	std::string vertexShaderFile,
	std::string fragmentShaderFile,
	std::string programName,
	std::vector<std::string> uniforms)
{
	std::cout << "Compiling program: " << programName << std::endl;

	std::string v_shader = FileStreams::ReadFile(vertexShaderFile);
	std::string f_shader = FileStreams::ReadFile(fragmentShaderFile);

	const char* v_shader_ = v_shader.c_str();
	const char* f_shader_ = f_shader.c_str();

	GLint result = GL_FALSE;
	int infoLogLength;

	// Vertex shader creation and compilation
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &v_shader_, NULL);
	glCompileShader(vs);

	// Vertex shader error check
	glGetShaderiv(vs, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vs, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0) {
		std::vector<char> VertexShaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(vs, infoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("Vertex shader compilation log:\n%s", &VertexShaderErrorMessage[0]);
	}

	// Fragment shader creation and compilation
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &f_shader_, NULL);
	glCompileShader(fs);

	// Fragment shader error check
	glGetShaderiv(fs, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fs, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0) {
		std::vector<char> FragmentShaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(fs, infoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		printf("Fragment shader compilation log:\n%s", &FragmentShaderErrorMessage[0]);
	}

	// Shader program and link
	GLuint program = glCreateProgram();
	glAttachShader(program, fs);
	glAttachShader(program, vs);
	glLinkProgram(program);

	// Program error check
	glGetProgramiv(program, GL_LINK_STATUS, &result);
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0) {
		std::vector<char> ProgramErrorMessage(infoLogLength + 1);
		glGetProgramInfoLog(program, infoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("Program link log:\n%s", &ProgramErrorMessage[0]);
	}

	ShaderProgram shaderProgram(vs, fs, program, programName);

	// Get uniforms
	for (auto &uniform : uniforms) {
		int tmp = glGetUniformLocation(program, uniform.c_str());
		shaderProgram.uniform(uniform, tmp);
	}

	return shaderProgram;
}
