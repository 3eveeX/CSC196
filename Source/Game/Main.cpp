#include <SDL3/SDL.h>
#include <iostream>
#include "Math/Math.h"
#include "Core/Random.h"

    int main(int argc, char* argv[]) {
        SDL_Init(SDL_INIT_VIDEO);

        SDL_Window* window = SDL_CreateWindow("SDL3 Project", 1280, 1024, 0);
        if (window == nullptr) {
            std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return 1;
        }

        SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
        if (renderer == nullptr) {
            std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 1;
        }

        SDL_Event e;
        bool quit = false;



        while (!quit) {
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_EVENT_QUIT) {
                    quit = true;
                }
            }

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set render draw color to black
            SDL_RenderClear(renderer); // Clear the renderer

            for (int i = 0; i < 199; i++) {
            SDL_SetRenderDrawColor(renderer, whermst::random::getRandomInt(255, 0), whermst::random::getRandomInt(255, 0), whermst::random::getRandomInt(255, 0), 255); // Set random draw color
            SDL_RenderLine(renderer, whermst::random::getRandomFloat() + whermst::random::getRandomInt(1280, 0), whermst::random::getRandomFloat() + whermst::random::getRandomInt(1024, 0), whermst::random::getRandomFloat() + whermst::random::getRandomInt(1280, 0), whermst::random::getRandomFloat() + whermst::random::getRandomInt(1024, 0));
            }
            for (int i = 0; i < 299; i++) {
                SDL_SetRenderDrawColor(renderer, whermst::random::getRandomInt(255, 0), whermst::random::getRandomInt(255, 0), whermst::random::getRandomInt(255, 0), 255); // Set random draw color
				SDL_RenderPoint(renderer, whermst::random::getRandomFloat() + whermst::random::getRandomInt(1280, 0), whermst::random::getRandomFloat() + whermst::random::getRandomInt(1024, 0));
            }
            SDL_RenderPresent(renderer); // Render the screen
        }

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();

        return 0;
    }
