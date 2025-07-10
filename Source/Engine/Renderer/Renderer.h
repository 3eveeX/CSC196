#pragma once
#include <SDL3/SDL.h>
#include <iostream>

namespace whermst {
	class Renderer {
	public:
		Renderer() = default;

		bool Initialize();

		void CloseWindow();
		bool CreateWindow(const std::string& name, int width, int height);

		void SetColour(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
		void DrawLine(float x1, float y1, float x2, float y2);
		void DrawPoint(float x1, float y1);

		void Clear();
		void Present();
	private:
		SDL_Window* _window = nullptr;
		SDL_Renderer* _renderer = nullptr;

	};
}