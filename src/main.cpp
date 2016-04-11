#include <iostream>

#include "includes/gl.hpp"
#include "includes/sdl.hpp"
#include "Window.hpp"
#include "OpenGLContext.hpp"
#include "Scene.hpp"
#include "MeshFactory.hpp"
#include "Mesh.hpp"

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

    Viewport viewport(1600, 900);
    Window window(viewport, false);
    OpenGLContext gl_context(4, 1, window);

    Mesh flat_mesh = MeshFactory::createFlatMesh();
    shared_ptr<Mesh> flat_mesh_ptr = make_shared<Mesh>(flat_mesh);

    float aspect_ratio = viewport.getAspectRatio();
    Scene scene(aspect_ratio, flat_mesh_ptr);

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
