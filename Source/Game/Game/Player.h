#pragma once
#include "Framework/Actor.h"

class Player : public whermst::Actor{
public:
	Player() = default;
	Player(const whermst::Transform& transform, std::shared_ptr<class whermst::Model> model) :
		Actor{ transform, model } 
	{}

	void Update(float dt) override;



private:

};
