#pragma once
#include "../Math/Transform.h"


namespace whermst {
	class Actor {
	public:
		Actor() = default;
		Actor(const Transform& transform, class Model* model) :
			_transform{ transform },
			_model{ model }
		{}

		virtual void Update(float dt);
		virtual void Draw(class Renderer& renderer);

		Transform& GetTransform() { return _transform; }

	protected:
		Transform _transform;
		Model* _model;

	};
}