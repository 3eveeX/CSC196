#include <iostream>
#include <vector>
#include <memory>

#include "Math/Math.h"
#include "Core/Random.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Math/Vector2.h"
#include "Core/Time.h"
#include "Game/Actor.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Math/Vector3.h"
#include "Math/Transform.h"
#include "Game/Scene.h"

#include "Game/Player.h"

int main(int argc, char* argv[]) {

    

    //initialize engine systems
    whermst::Time time;
    std::unique_ptr<whermst::Renderer> renderer = std::make_unique<whermst::Renderer>();

    renderer -> Initialize();
    renderer -> CreateWindow("Space", 1280, 1024);

    std::unique_ptr<whermst::InputSystem> input = std::make_unique<whermst::InputSystem>();
    input -> Initialize();

    // create audio system
    std::unique_ptr<whermst::AudioSystem> audio = std::make_unique<whermst::AudioSystem>();
    audio -> Initialize();
    

    std::vector<whermst::vec2> points{
        {10, 0},
        {-10, -3},
        {-5, 0},
        {-10, 3}
    };

	std::shared_ptr<whermst::Model> model = std::make_shared<whermst::Model>(points, whermst::vec3{ 1.0f, 1.0f, 1.0f });
	//whermst::Model* model = new whermst::Model(points, { whermst::random::getRandomFloat(), whermst::random::getRandomFloat(), whermst::random::getRandomFloat()});
    
    whermst::Scene scene;


    for (int i = 0; i < 10; i++) {
        whermst::Transform transform{ whermst::vec2{whermst::random::getRandomFloat() * 1280, whermst::random::getRandomFloat()* 1024}, 0, 10};
        std::unique_ptr<Player> player = std::make_unique<Player>( transform, model );
		scene.AddActor(std::move(player));
    }
    SDL_Event e;
    bool quit = false;

    //vec2 v(290, 300);

    audio -> AddSound("test.wav");
    audio -> AddSound("bass.wav", "bass");
    audio -> AddSound("clap.wav", "clap");
    audio -> AddSound("close-hat.wav", "close-hat");
    audio -> AddSound("cowbell.wav", "cowbell");
    audio -> AddSound("open-hat.wav", "open-hat");
    audio -> AddSound("snare.wav", "snare");

    //audio.PlaySound("filename");

    //std::vector<whermst::vec2> points;
    //std::vector<std::vector<whermst::vec2>> confirmed;
    //MAIN LOOP
    while (!quit) {
        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
        //update engine systems
        input -> Update();
        audio -> Update();
        //get input
       /* if (input.GetKeyDown(SDL_SCANCODE_A)) audio.PlaySound("bass");
        if (input.GetKeyDown(SDL_SCANCODE_S)) audio.PlaySound("clap");
        if (input.GetKeyDown(SDL_SCANCODE_D)) audio.PlaySound("close-hat");
        if (input.GetKeyDown(SDL_SCANCODE_F)) audio.PlaySound("cowbell");
        if (input.GetKeyDown(SDL_SCANCODE_G)) audio.PlaySound("open-hat");
        if (input.GetKeyDown(SDL_SCANCODE_H)) audio.PlaySound("snare");*/
		//if (input.GetKeyDown(SDL_SCANCODE_A)) transform.rotation -= whermst::math::degToRad(45 * time.GetDeltaTime());
		//if (input.GetKeyDown(SDL_SCANCODE_D)) transform.rotation += whermst::math::degToRad(45 * time.GetDeltaTime());
        
        float speed = 200;
        whermst::vec2 direction{ 0, 0 };

        if (input -> GetKeyDown(SDL_SCANCODE_W)) direction.y = -1; //* time.GetDeltaTime();
        if (input -> GetKeyDown(SDL_SCANCODE_S)) direction.y = 1; //* time.GetDeltaTime();
        if (input -> GetKeyDown(SDL_SCANCODE_A)) direction.x = -1; //* time.GetDeltaTime();
        if (input -> GetKeyDown(SDL_SCANCODE_D)) direction.x = 1; //* time.GetDeltaTime();

        if (direction.LengthSqr() > 0) { 
            direction = direction.Normalized();
            //for (auto& actor : actors) {
              //  actor -> GetTransform().position += (direction * speed) * time.GetDeltaTime();
           // }
        
        }



        //draw
        whermst::vec3 colour(0, 0, 0);

		renderer -> SetColourf(colour.r, colour.g, colour.b); // Set the colour to black

        //renderer.SetColour(0, 0, 0); // Set
        renderer -> Clear(); // Clear the renderer
        whermst::vec2 position = input -> GetMousePosition();

		renderer -> SetColourf(2, 0.3, 1); // Set the colour to white
       // model.Draw(renderer, input.GetMousePosition(), 0, 10);
		scene.Draw(*renderer);
       /* if (input.GetMouseButtonDown(whermst::InputSystem::MouseButton::Left)) {
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
        }*/
        /*for (int i = 1; i < points.size(); i++) {
            renderer.SetColour(255, 255, 255);
            renderer.DrawLine(points[i - 1].x, points[i - 1].y, points[i].x, points[i].y);

        }*/

       

       
        renderer -> Present(); // Render the screen
    }
    //delete model;

    audio -> Close();
	input -> Close();
    renderer -> CloseWindow();

    return 0;
}
