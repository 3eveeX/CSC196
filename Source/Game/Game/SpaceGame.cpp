#include "SpaceGame.h"
#include "Player.h"
#include "Framework/Scene.h"
#include "Math/Vector2.h"
#include "Renderer/Model.h"
#include "Core/Random.h"
#include "../Engine/Engine.h"
#include "Renderer/Renderer.h"

bool SpaceGame::Initialize()
{
	_scene = std::make_unique<whermst::Scene>();

    std::vector<whermst::vec2> points{
       {10, 0},
       {-10, -3},
       {-5, 0},
       {-10, 3}
    };

    std::shared_ptr<whermst::Model> model = std::make_shared<whermst::Model>(points, whermst::vec3{ 1.0f, 1.0f, 1.0f });
    //whermst::Model* model = new whermst::Model(points, { whermst::random::getRandomFloat(), whermst::random::getRandomFloat(), whermst::random::getRandomFloat()});
    whermst::Transform transform{ whermst::vec2{whermst::GetEngine().GetRenderer().GetWidth() * 0.5f, whermst::GetEngine().GetRenderer().GetHeight() * 0.5f}, 0, 10};
    std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
    _scene->AddActor(std::move(player));
    
    /*for (int i = 0; i < 10; i++) {
        whermst::Transform transform{ whermst::vec2{whermst::random::getRandomFloat() * 1280, whermst::random::getRandomFloat() * 1024}, 0, 10 };
        std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
        _scene->AddActor(std::move(player));
    }*/
    
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
