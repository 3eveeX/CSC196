#pragma once
#include <memory>
#include <string>
#include "../Math/Transform.h"


namespace whermst {
	class Actor {
	public:
		std::string name;
		std::string tag;

		vec2 velocity{ 0, 0 };
	public:
		Actor() = default;
		Actor(const Transform& transform, std::shared_ptr<class Model> model) :
			_transform{ transform },
			_model{ model }
		{}

		virtual void Update(float dt);
		virtual void Draw(class Renderer& renderer);

		Transform& GetTransform() { return _transform; }

	protected:
		Transform _transform;
		std::shared_ptr<Model> _model;

	};
}