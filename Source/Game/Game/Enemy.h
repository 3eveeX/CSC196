#pragma once
#include "Framework/Actor.h"

class Enemy : public whermst::Actor {
public:
	Enemy() = default;
	Enemy(const whermst::Transform& transform, std::shared_ptr<class whermst::Model> model) :
		Actor{ transform, model }
	{
	}

	void Update(float dt) override;



private:

};

