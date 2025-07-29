#pragma once
#include "Framework/Game.h"

class SpaceGame : public whermst::Game {
public:
	enum class GameState {
		Initialize,
		Title,
		StartGame,
		StartRound,
		Game,
		PlayerDead,
		GameOver
	};
public:

	SpaceGame() = default;

	// Inherited via Game
	bool Initialize() override;

	void Update(float dt) override;

	void Shutdown() override;

	void Draw() override;

private:
	GameState _gameState = GameState::Initialize;
	float _enemySpawnTimer{ 0 };
};

