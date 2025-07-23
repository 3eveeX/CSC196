#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include "Math/Math.h"

void Player::Update(float dt)
{
    float speed = 200;
	float rotateRate = 180;
	float thrust = 0;

    float rotate = 0;
    if (whermst::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate = -1;
    if (whermst::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_D)) rotate = 1;

    if (whermst::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust = 1;
    if (whermst::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust = -1;

	_transform.rotation += (rotate * rotateRate) * dt;

    whermst::vec2 direction{ 1, 0 };
	whermst::vec2 force = direction.rotate(whermst::math::degToRad(_transform.rotation)) * thrust * speed;

	 velocity += force * dt;

	 Actor::Update(dt);
   
}
