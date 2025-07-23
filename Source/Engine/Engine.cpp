#include "Engine.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"

namespace whermst
{
	Engine& GetEngine()
	{
		static Engine engine;
		return engine;
	}
	bool Engine::Initialize()
	{
		_renderer = std::make_unique<whermst::Renderer>();

		_renderer->Initialize();
		_renderer->CreateWindow("Space", 1280, 1024);

		_input = std::make_unique<whermst::InputSystem>();
		_input->Initialize();

		_audio = std::make_unique<whermst::AudioSystem>();
		_audio->Initialize();
		return true;
	}
	void Engine::Update()
	{
		_time.Tick();
		_input->Update();
		_audio->Update();
	}
	void Engine::Shutdown()
	{
	_audio->Close();
	_input->Close();
	_renderer->CloseWindow();
	}
}