#include "includes/gl.hpp"
#include "includes/sdl.hpp"
#include "Window.hpp"
#include "OpenGLContext.hpp"
#include "Entity.hpp"
#include "EntityManager.hpp"
#include "Mesh.hpp"
#include "MeshFactory.hpp"
#include "FlatDrawable.hpp"

#include "component_managers/NameComponentManager.hpp"
#include "component_managers/MeshComponentManager.hpp"
#include "component_managers/SpriteDrawableComponentManager.hpp"

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
    MeshComponentManager mesh_component_manager;
    SpriteDrawableComponentManager sprite_drawable_component_manager;

    vector<Entity> entities = {
        entity_manager.create(),
        entity_manager.create(),
        entity_manager.create(),
        entity_manager.create(),
        entity_manager.create()
    };

    MeshFactory mesh_factory;
    Mesh flat_mesh = mesh_factory.createFlatMesh();
    shared_ptr<Mesh> flat_mesh_ptr = make_shared<Mesh>(flat_mesh);

    mesh_component_manager.setMesh(entities[0], flat_mesh_ptr);
    name_component_manager.setName(entities[0], "Snorlax");
    sprite_drawable_component_manager.registerEntity(entities[0]);

    // Display loop
    while(window.isOpen()) {
        window.clearBuffers();
        handleInputs(window);

        sprite_drawable_component_manager.update(mesh_component_manager);

        window.display();
    }

    // Close the window
    window.close();

    // Nothing went wrong!
    return 0;
}
