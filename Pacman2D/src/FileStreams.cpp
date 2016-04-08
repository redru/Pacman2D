#include "FileStreams.h"

std::string FileStreams::ReadFile(std::string file) {
	std::ifstream t(file);
	std::string str((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());

	return str;
}
