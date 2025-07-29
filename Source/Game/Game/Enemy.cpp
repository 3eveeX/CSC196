#include "Enemy.h"
#include "Engine.h"
#include "Framework/Scene.h"
#include "Renderer/Renderer.h"
#include "Player.h"

void Enemy::Update(float dt)
{
	

	Player* player = _scene -> GetActorByName<Player>("Player");
	if (player) {
		whermst::vec2 direction{ 0, 0 };
		direction = player->transform.position - transform.position;
		direction.Normalized();
		transform.rotation = whermst::math::radToDeg(direction.Angle());
	}

	whermst::vec2 force = whermst::vec2{1, 0}.rotate(whermst::math::degToRad(transform.rotation)) * speed;
	velocity += force * dt;

	transform.position.x = whermst::math::wrap(transform.position.x, 0.0f, (float)whermst::GetEngine().GetRenderer().GetWidth());
	transform.position.y = whermst::math::wrap(transform.position.y, 0.0f, (float)whermst::GetEngine().GetRenderer().GetHeight());

	Actor::Update(dt);
}
