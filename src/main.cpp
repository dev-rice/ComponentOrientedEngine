#include "includes/gl.hpp"
#include "includes/sdl.hpp"
#include "Window.hpp"
#include "OpenGLContext.hpp"
#include "Entity.hpp"
#include "EntityManager.hpp"
#include "component_managers/NameComponentManager.hpp"
#include "ShaderProgram.hpp"
#include "ShaderProgramFactory.hpp"
#include "Mesh.hpp"
#include "MeshFactory.hpp"
#include "FlatDrawable.hpp"

#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <cstdio>

using namespace std;

void handleInputs(Window& window) {
    // Misleading argument and function name combination. The input handling does not draw from the mouse or window at all, it simply does things with them

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

    EntityManager entity_manager;
    NameComponentManager name_component_manager;

    vector<Entity> entities = {
        entity_manager.create(),
        entity_manager.create(),
        entity_manager.create(),
        entity_manager.create(),
        entity_manager.create()
    };

    ShaderProgramFactory shader_program_factory;
    ShaderProgram flat_shader = shader_program_factory.createShaderProgram("shaders/flat.vs", "shaders/flat.fs");

    MeshFactory mesh_factory;
    Mesh flat_mesh = mesh_factory.createFlatMesh();
    FlatDrawable flat_drawable(flat_mesh, flat_shader);
    Transform2D flat_transform;
    flat_transform.setScale(glm::vec2(0.5, 0.5));

    // Display loop
    while(window.isOpen()) {
        window.clearBuffers();
        handleInputs(window);

        flat_drawable.draw(flat_transform);

        window.display();
    }

    // Close the window
    window.close();

    // Nothing went wrong!
    return 0;
}
