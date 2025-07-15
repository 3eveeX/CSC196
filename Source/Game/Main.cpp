#include <iostream>
#include <vector>
#include "Math/Math.h"
#include "Core/Random.h"
#include "Renderer/Renderer.h"
#include "Math/Vector2.h"
#include "Core/Time.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"

int main(int argc, char* argv[]) {
    //initialize engine systems
    whermst::Time time;
    whermst::Renderer renderer;

    renderer.Initialize();
    renderer.CreateWindow("Space", 1280, 1024);

    whermst::InputSystem input;
    input.Initialize();

    // create audio system
    whermst::AudioSystem audio;
    audio.Initialize();
    

    

    SDL_Event e;
    bool quit = false;

    //vec2 v(290, 300);

    audio.AddSound("test.wav");
    audio.AddSound("bass.wav", "bass");
    audio.AddSound("clap.wav", "clap");
    audio.AddSound("close-hat.wav", "close-hat");
    audio.AddSound("cowbell.wav", "cowbell");
    audio.AddSound("open-hat.wav", "open-hat");
    audio.AddSound("snare.wav", "snare");

    audio.PlaySound("filename");

    std::vector<whermst::vec2> points;
    std::vector<std::vector<whermst::vec2>> confirmed;
    //MAIN LOOP
    while (!quit) {
        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
        //update engine systems
        input.Update();
        audio.Update();
        //get input
        if (input.GetKeyPressed(SDL_SCANCODE_A)) audio.PlaySound("bass");
        if (input.GetKeyPressed(SDL_SCANCODE_S)) audio.PlaySound("clap");
        if (input.GetKeyPressed(SDL_SCANCODE_D)) audio.PlaySound("close-hat");
        if (input.GetKeyPressed(SDL_SCANCODE_F)) audio.PlaySound("cowbell");
        if (input.GetKeyPressed(SDL_SCANCODE_G)) audio.PlaySound("open-hat");
        if (input.GetKeyPressed(SDL_SCANCODE_H)) audio.PlaySound("snare");
        



      

        //draw
        renderer.SetColour(0, 0, 0); // Set
        renderer.Clear(); // Clear the renderer
        whermst::vec2 position = input.GetMousePosition();
        if (input.GetMouseButtonDown(whermst::InputSystem::MouseButton::Left)) {
            if (points.empty()) points.push_back(position);
            else if ((position - points.back()).Length() > 10) points.push_back(position);
        }
        if (input.GetMouseButtonReleased(whermst::InputSystem::MouseButton::Left)) {
            confirmed.push_back(points);
            points.clear();
        }
        if (input.GetMouseButtonPressed(whermst::InputSystem::MouseButton::Right)) {
        confirmed.clear();
		points.clear();
        }
        if (!confirmed.empty()) {
            for (int i = 0; i < confirmed.size(); i++) {
                if (confirmed[i].size() > 1) {
                    for (int j = 1; j < confirmed[i].size(); j++) {
                        renderer.SetColour(255, 255, 255);
                        renderer.DrawLine(confirmed[i][j - 1].x, confirmed[i][j - 1].y, confirmed[i][j].x, confirmed[i][j].y);

                    }
                }
            }
        }
        for (int i = 1; i < points.size(); i++) {
            renderer.SetColour(255, 255, 255);
            renderer.DrawLine(points[i - 1].x, points[i - 1].y, points[i].x, points[i].y);

        }

       

       
        renderer.Present(); // Render the screen
    }
    audio.Close();
    renderer.CloseWindow();

    return 0;
}
