#pragma once
#include <glm\vec3.hpp>

class Transform {

public:
	Transform(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 size = glm::vec3(1.0f, 1.0f, 1.0f)) :
		_position(position), _rotation(rotation), _size(size) {
		_enabled = true;
	}

	// Postion
	inline void position(glm::vec3 position) { _position = position; }
	inline glm::vec3 position() { return _position; }

	inline void positionX(float x) { _position.x = x; }
	inline float positionX() { return _position.x; }

	inline void positionY(float y) { _position.y = y; }
	inline float positionY() { return _position.y; }

	inline void positionZ(float z) { _position.z = z; }
	inline float positionZ() { return _position.z; }

	// Rotation
	inline void rotation(glm::vec3 rotation) { _rotation = rotation; }
	inline glm::vec3 rotation() { return _rotation; }

	inline void rotationX(float x) { _rotation.x = x; }
	inline float rotationX() { return _rotation.x; }

	inline void rotationY(float y) { _rotation.y = y; }
	inline float rotationY() { return _rotation.y; }

	inline void rotationZ(float z) { _rotation.z = z; }
	inline float rotationZ() { return _rotation.z; }

	// Size
	inline void size(glm::vec3 size) { _size = size; }
	inline glm::vec3 size() { return _size; }

	inline void sizeX(float x) { _size.x = x; }
	inline float sizeX() { return _size.x; }

	inline void sizeY(float y) { _size.y = y; }
	inline float sizeY() { return _size.y; }

	inline void sizeZ(float z) { _size.z = z; }
	inline float sizeZ() { return _size.z; }

	// State
	inline void enabled(bool enabled) { _enabled = enabled; }
	inline bool enabled() { return _enabled; }

private:
	glm::vec3 _position;
	glm::vec3 _rotation;
	glm::vec3 _size;

	bool _enabled;

};