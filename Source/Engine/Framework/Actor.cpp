#include "Actor.h"
#include "../Renderer/Model.h"

namespace whermst{


	void Actor::Update(float dt)
	{
		transform.position += velocity * dt;
		velocity = velocity * (1.0f - damping * dt);
	}

	void Actor::Draw(Renderer& renderer)
	{
		_model->Draw(renderer, transform);
	}
}