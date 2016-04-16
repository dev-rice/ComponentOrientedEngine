#include <iostream>

#include "includes/gl.hpp"
#include "includes/sdl.hpp"
#include "Window.hpp"
#include "OpenGLContext.hpp"
#include "Scene.hpp"
#include "MeshFactory.hpp"
#include "Mesh.hpp"
#include "V8Thing.hpp"

using namespace std;

void handleInputs(Window& window) {
    // Key repeat delay input
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            window.requestClose();
        }

        SDL_Scancode key_scancode = event.key.keysym.scancode;
        if (key_scancode == SDL_SCANCODE_ESCAPE) {
            window.requestClose();
        }

    }

}

int main(int argc, char* argv[]) {

    Viewport viewport(1200, 900);
    Window window(viewport, false);
    OpenGLContext gl_context(4, 1, window);

    Scene scene = Scene::fromFile(viewport, "res/scenes/test_scene.json");

    V8Thing v8_thing;
    v8_thing.runScript("res/scripts/testing_class_script.js");

    // Display loop
    while(window.isOpen()) {
        window.clearBuffers();
        handleInputs(window);

        scene.update();

        window.display();
    }

    // Close the window
    window.close();

    // Nothing went wrong!
    return 0;
}
