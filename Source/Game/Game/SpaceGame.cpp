#include "SpaceGame.h"
#include "Player.h"
#include "Framework/Scene.h"
#include "Math/Vector2.h"
#include "Renderer/Model.h"
#include "Core/Random.h"
#include "../Engine/Engine.h"
#include "Renderer/Renderer.h"
#include "Enemy.h"

bool SpaceGame::Initialize()
{
	_scene = std::make_unique<whermst::Scene>();

    std::vector<whermst::vec2> points{
       {10, 0},
       {-10, -3},
       {-5, 0},
       {-10, 3}
    };

    std::vector<whermst::vec2> enemyPoints{
    { -2, -5 },
    { 0, -5 },
    { 1, -4 },
    { 0, -3 },
    { 1, 0 },
    { -1, 2 },
    { -5, 1 },
    { -5, -2 },
    { -4, -3 },
    { -4, -5 },
    { -3, -6 },
    };

    std::shared_ptr<whermst::Model> model = std::make_shared<whermst::Model>(points, whermst::vec3{ 1.0f, 1.0f, 1.0f });
    //whermst::Model* model = new whermst::Model(points, { whermst::random::getRandomFloat(), whermst::random::getRandomFloat(), whermst::random::getRandomFloat()});
    whermst::Transform transform{ whermst::vec2{whermst::GetEngine().GetRenderer().GetWidth() * 0.5f, whermst::GetEngine().GetRenderer().GetHeight() * 0.5f}, 0, 5};
    std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
	player->speed = 500.0f;
	player->rotateRate = 180.0f;
    player->damping = 1.5f;
	player->name = "Player";
    _scene->AddActor(std::move(player));
    
    for (int i = 0; i < 1000; i++) {
        std::shared_ptr<whermst::Model> enemyModel = std::make_shared<whermst::Model>(enemyPoints, whermst::vec3{ whermst::random::getRandomFloat(), whermst::random::getRandomFloat(), whermst::random::getRandomFloat() });
        whermst::Transform transform{ whermst::vec2{whermst::random::getRandomFloat() * 1280, whermst::random::getRandomFloat() * 1024}, 0, 5 };
        std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(transform, enemyModel);
		enemy->damping = 0.2f;
		enemy->speed = 100.0f + whermst::random::getRandomFloat() * 100.0f; // Random speed between 100 and 200
        _scene->AddActor(std::move(enemy));
    }
    
    return false;
}    

void SpaceGame::Update()
{
    _scene -> Update(whermst::GetEngine().GetTime().GetDeltaTime());    
}

void SpaceGame::Shutdown()
{
    //
}

void SpaceGame::Draw()
{
    _scene -> Draw(whermst::GetEngine().GetRenderer());
}
