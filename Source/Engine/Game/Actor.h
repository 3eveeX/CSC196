#pragma once
#include <memory>
#include "../Math/Transform.h"


namespace whermst {
	class Actor {
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