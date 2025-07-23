#pragma once
#include "Framework/Game.h"

class SpaceGame : public whermst::Game {
public:

	SpaceGame() = default;

	// Inherited via Game
	bool Initialize() override;

	void Update() override;

	void Shutdown() override;

	void Draw() override;

private:

};

