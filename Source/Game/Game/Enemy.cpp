#include "Enemy.h"
#include "Engine.h"
#include "Framework/Scene.h"
#include "Renderer/Renderer.h"
#include "Player.h"
#include "Framework/Game.h"
#include "GameData.h"
#include "Projectile.h"
#include "Renderer/Model.h"
#include "Math/Vector3.h"
#include <Renderer/ParticleSystem.h>
#include <Core/Random.h>

void Enemy::Update(float dt)
{
	whermst::GetEngine().GetAudio().AddSound("explode.mp3", "Explode");

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
	fireTimer -= dt;
	if (fireTimer <= 0) {
		fireTimer = fireTime;
		std::shared_ptr<whermst::Model> model = std::make_shared<whermst::Model>(GameData::projectilePoints, whermst::vec3{ 1.0f, 1.0f, 0.0f });
		whermst::Transform transform{ this->transform.position, this->transform.rotation, 2.0f };
		auto projectile = std::make_unique<Projectile>(transform, model);
		projectile->speed = 250.0f;
		projectile->lifespan = 1.5f;
		projectile->name = "Projectile";
		projectile->tag = "enemy";
		_scene->AddActor(std::move(projectile));
	}
	Actor::Update(dt);
}

void Enemy::OnCollision(Actor* other)
{
	if (whermst::tolower(other->tag) != whermst::tolower(tag)) {
		whermst::GetEngine().GetAudio().PlaySound("Explode");
		destroyed = true;
		_scene->GetGame()->AddPoints(100);
		for (int i = 0; i < 100; i++) {
			whermst::Particle particle;
			particle.position = transform.position;
			particle.velocity = (whermst::random::onUnitCircle() * 3) * whermst::random::getReal(1.0f, 40.0f);
			int colourRandom = whermst::random::getInt() % 3;
			if( colourRandom == 0) {
				particle.colour = whermst::vec3{ 1.0f, 0, 0 }; // Red
			}
			else if (colourRandom == 1) {
				particle.colour = whermst::vec3{ 1.0, .8f, 0.1f }; // orange
			}
			else {
				particle.colour = whermst::vec3{ 1.0f, 1.0f, 0 }; // yellow
			}
			particle.lifespan = 2;
			particle.active = true;
			whermst::GetEngine().GetPT().AddParticle(particle);
		}
	}
}
