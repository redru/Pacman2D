#pragma once
#include <iostream>
#include <memory>

#include "Renderer.h"
#include "Transform.h"

class Engine;

class Entity {

public:
	Entity(Engine& engine) : _engine(std::shared_ptr<Engine>(&engine)) {
		_enabled = true;
	}

	/* ~Entity() {
		std::cout << "Destroying Entity" << std::endl;
		_transform.reset();
	} */

	inline Engine& engine() const { return *_engine; }
	inline Transform& transform() { return _transform; }
	inline void enabled(bool enabled) { _enabled = enabled; }
	inline bool enabled() { return _enabled; }

private:
	// Components
	Transform _transform;
	Renderer _renderer;
	
	// Shared engine object
	std::shared_ptr<Engine> _engine;

	// Entity state
	bool _enabled;

};
