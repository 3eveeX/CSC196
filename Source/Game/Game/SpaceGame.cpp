#include "SpaceGame.h"
#include "Player.h"
#include "Framework/Scene.h"
#include "Math/Vector2.h"
#include "Renderer/Model.h"
#include "Core/Random.h"
#include "../Engine/Engine.h"
#include "Renderer/Renderer.h"
#include "Enemy.h"
#include "GameData.h"
#include "Renderer/Font.h"

bool SpaceGame::Initialize()
{
	_scene = std::make_unique<whermst::Scene>(this);
    
    return true;

}    

void SpaceGame::Update(float dt)
{
    switch (_gameState)
    {
    case SpaceGame::GameState::Initialize:
        _titleFont = std::make_shared<whermst::Font>();
		_titleFont->Load("Assets/Fonts/PressStart2P-Regular.ttf", 128);

        _uiFont = std::make_shared<whermst::Font>();
		_uiFont->Load("Assets/Fonts/PressStart2P-Regular.ttf", 128);

        _titleText = std::make_unique<whermst::Text>(_titleFont);
        _scoreText = std::make_unique<whermst::Text>(_uiFont);
        _livesText = std::make_unique<whermst::Text>(_uiFont);
        

		_gameState = SpaceGame::GameState::StartGame;
        break;
    case SpaceGame::GameState::Title:
        if (whermst::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_SPACE)) {
            _gameState = SpaceGame::GameState::StartGame;
        }
        break;
        case SpaceGame::GameState::StartGame:
            _score = 0;
			_lives = 3;
			_gameState = SpaceGame::GameState::StartRound;
			break;
    case SpaceGame::GameState::StartRound:
    {
        std::shared_ptr<whermst::Model> model = std::make_shared<whermst::Model>(GameData::shipPoints, whermst::vec3{ 1.0f, 1.0f, 1.0f });
        whermst::Transform transform{ whermst::vec2{whermst::GetEngine().GetRenderer().GetWidth() * 0.5f, whermst::GetEngine().GetRenderer().GetHeight() * 0.5f}, 0, 5 };
        auto player = std::make_unique<Player>(transform, model);
        player->speed = 500.0f;
        player->rotateRate = 180.0f;
        player->damping = .9;
        player->fireTime = 0.5f;
		player->fireTimer = player->fireTime;
        player->name = "Player";
        player->tag = "Player";
        _scene->AddActor(std::move(player));
    }
	_gameState = SpaceGame::GameState::Game;
        break;
	case SpaceGame::GameState::Game:
        _enemySpawnTimer -= dt;
        if (_enemySpawnTimer <= 0) {
            _enemySpawnTimer = 4.0f;
            std::shared_ptr<whermst::Model> enemyModel = std::make_shared<whermst::Model>(GameData::enemyPoints, whermst::vec3{ whermst::random::getReal(), whermst::random::getReal(), whermst::random::getReal() });
                  whermst::Transform transform{ whermst::vec2{whermst::random::getReal() * 1280, whermst::random::getReal() * 1024}, 0, 5 };
                  std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(transform, enemyModel);
                  enemy->damping = 0.2f;
                  enemy->speed = 00.0f  + whermst::random::getReal() * 100.0f; // Random speed between 100 and 200
                  enemy->tag = "Enemy";
                  _scene->AddActor(std::move(enemy));
        }

        break;
	case SpaceGame::GameState::PlayerDead:
		_lives--;
        if (_lives == 0) {
            _gameState = SpaceGame::GameState::GameOver;
        }
        else
        {
			_gameState = GameState::StartRound;
        }
		break;
    case SpaceGame::GameState::GameOver:
        break;
    default:
        break;
    }
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
