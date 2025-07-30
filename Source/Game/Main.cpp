#include <iostream>
#include <vector>
#include <memory>

#include "Math/Math.h"
#include "Core/Random.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Math/Vector2.h"
#include "Core/Time.h"
#include "Framework/Actor.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Math/Vector3.h"
#include "Math/Transform.h"
#include "Framework/Scene.h"
#include "Engine.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Core/File.h"

#include "Game/Player.h"
#include "Game/SpaceGame.h"


int main(int argc, char* argv[]) {

    // Test getInt() variants
    std::cout << "Integer Functions:\n";
    std::cout << "getInt(): " << whermst::random::getInt() << "\n";
    std::cout << "getInt(): " << whermst::random::getInt() << "\n";
    std::cout << "getInt(10): " << whermst::random::getInt(10) << "\n";
    std::cout << "getInt(10): " << whermst::random::getInt(10) << "\n";
    std::cout << "getInt(5, 15): " << whermst::random::getInt(5, 15) << "\n";
    std::cout << "getInt(5, 15): " << whermst::random::getInt(5, 15) << "\n";
    std::cout << "getInt(-10, 10): " << whermst::random::getInt(-10, 10) << "\n\n";

    // Test getReal() variants with float
    std::cout << "Float Functions:\n";
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "getReal<float>(): " << whermst::random::getReal<float>() << "\n";
    std::cout << "getReal<float>(): " << whermst::random::getReal<float>() << "\n";
    std::cout << "getReal<float>(5.0f): " << whermst::random::getReal<float>(5.0f) << "\n";
    std::cout << "getReal<float>(2.5f, 7.5f): " << whermst::random::getReal<float>(2.5f, 7.5f) << "\n";
    std::cout << "getReal<float>(-1.0f, 1.0f): " << whermst::random::getReal<float>(-1.0f, 1.0f) << "\n\n";

    // Test getReal() variants with double
    std::cout << "Double Functions:\n";
    std::cout << std::setprecision(10);
    std::cout << "getReal<double>(): " << whermst::random::getReal<double>() << "\n";
    std::cout << "getReal<double>(100.0): " << whermst::random::getReal<double>(100.0) << "\n";
    std::cout << "getReal<double>(0.0, 2.0): " << whermst::random::getReal<double>(0.0, 2.0) << "\n\n";

    // Test getBool()
    std::cout << "Boolean Functions:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << "getBool(): " << std::boolalpha << whermst::random::getBool() << "\n";
    }
    std::cout << "\n";

    // Get current directory path
    std::cout << "Directory Operations:\n";
    std::cout << "Current directory: " << whermst::file::GetCurrentDirectory() << "\n";

    // Set current directory path (current path + "Assets")
    std::cout << "Setting directory to 'Assets'...\n";
    whermst::file::SetCurrentDirectory("Assets");
    std::cout << "New directory: " << whermst::file::GetCurrentDirectory() << "\n\n";

    // Get filenames in the current directory
    std::cout << "Files in Directory:\n";
    auto filenames = whermst::file::GetFilesInDirectory(whermst::file::GetCurrentDirectory());
    for (const auto& filename : filenames) {
        std::cout << filename << "\n";
    }
    std::cout << "\n";

    // Get filename (filename.extension) only
    if (!filenames.empty()) {
        std::cout << "Path Analysis:\n";
        std::string filename = whermst::file::GetFilename(filenames[0]);
        std::cout << "Filename only: " << filename << "\n";

        // Get extension only
        std::string ext = whermst::file::GetExtension(filenames[0]);
        std::cout << "Extension: " << ext << "\n\n";
    }

    // Read and display text file
    std::cout << "Text File Reading:\n";
    std::string str;
    bool success = whermst::file::ReadTextFile("test.txt", str);
    if (success) {
        std::cout << "Contents of test.txt:\n";
        std::cout << str << "\n";
    }
    else {
        std::cout << "Failed to read test.txt\n";
    }

    //initialize engine 
	whermst::GetEngine().Initialize();
    
    //initialize game
	std::unique_ptr<SpaceGame> game = std::make_unique<SpaceGame>();
	game->Initialize();

   //initialize font
	whermst::Font* font = new whermst::Font();
	font->Load("8bitOperatorPlus8-Regular.ttf", 20);

    //initialize Text
    //whermst::Text* text = new whermst::Text(font);
    //text->Create(whermst::GetEngine().GetRenderer(), "Hello World", whermst::vec3{1, 1, 1});

    SDL_Event e;
    bool quit = false;

    //vec2 v(290, 300);

    whermst::GetEngine().GetAudio().AddSound("test.wav");
    whermst::GetEngine().GetAudio().AddSound("bass.wav", "bass");
    whermst::GetEngine().GetAudio().AddSound("clap.wav", "clap");
    whermst::GetEngine().GetAudio().AddSound("close-hat.wav", "close-hat");
    whermst::GetEngine().GetAudio().AddSound("cowbell.wav", "cowbell");
    whermst::GetEngine().GetAudio().AddSound("open-hat.wav", "open-hat");
    whermst::GetEngine().GetAudio().AddSound("snare.wav", "snare");

    //audio.PlaySound("filename");

    //std::vector<whermst::vec2> points;
    //std::vector<std::vector<whermst::vec2>> confirmed;
    //MAIN LOOP
    while (!quit) {
        //update engine
		whermst::GetEngine().Update();
		game -> Update(whermst::GetEngine().GetTime().GetDeltaTime());
        
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
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

        if (whermst::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W)) direction.y = -1; 
        if (whermst::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_S)) direction.y = 1;
        if (whermst::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_A)) direction.x = -1;
        if (whermst::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_D)) direction.x = 1; 

        if (direction.LengthSqr() > 0) { 
            direction = direction.Normalized();
            //for (auto& actor : actors) {
              //  actor -> GetTransform().position += (direction * speed) * time.GetDeltaTime();
           // }
        
        }



        //draw
        whermst::vec3 colour(0, 0, 0);

		whermst::GetEngine().GetRenderer().SetColourf(colour.r, colour.g, colour.b); // Set the colour to black
        whermst::GetEngine().GetRenderer().Clear(); // Clear the renderer
        whermst::vec2 position = whermst::GetEngine().GetInput().GetMousePosition();

        whermst::GetEngine().GetRenderer().SetColourf(2, 0.3, 1); // Set the colour to white

        //text->Draw(whermst::GetEngine().GetRenderer(), 40.0f, 40.0f);
		game->Draw(); // Draw the game scene

       

       
        whermst::GetEngine().GetRenderer().Present(); // Render the screen
    }
	game->Shutdown(); // Shutdown the game
	game.release(); // Release the game object
	whermst::GetEngine().Shutdown(); // Shutdown the engine

    return 0;
}
