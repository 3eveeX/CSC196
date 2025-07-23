#include "Actor.h"
#include "../Renderer/Model.h"

namespace whermst{


	void Actor::Update(float dt)
	{
		_transform.position += velocity * dt;
	}

	void Actor::Draw(Renderer& renderer)
	{
		_model->Draw(renderer, _transform);
	}
}