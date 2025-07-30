#include "Projectile.h"
#include "Engine.h"
#include"Core/StringHelper.h"
#include "Framework/Scene.h"
#include "Renderer/Renderer.h"
#include "Player.h"

void Projectile::Update(float dt)
{
	whermst::vec2 force = whermst::vec2{ 1, 0 }.rotate(whermst::math::degToRad(transform.rotation)) * speed;
	velocity = force;

	transform.position.x = whermst::math::wrap(transform.position.x, 0.0f, (float)whermst::GetEngine().GetRenderer().GetWidth());
	transform.position.y = whermst::math::wrap(transform.position.y, 0.0f, (float)whermst::GetEngine().GetRenderer().GetHeight());

	Actor::Update(dt);
}

void Projectile::OnCollision(Actor* other)
{
	if (whermst::tolower(other->tag) != whermst::tolower(tag)) {
		destroyed = true;
	}
}
