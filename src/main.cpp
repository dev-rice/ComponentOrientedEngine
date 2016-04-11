#include "includes/gl.hpp"
#include "includes/sdl.hpp"
#include "Window.hpp"
#include "OpenGLContext.hpp"
#include "Entity.hpp"
#include "EntityManager.hpp"
#include "Mesh.hpp"
#include "MeshFactory.hpp"
#include "FlatDrawable.hpp"
#include "Texture.hpp"

#include "component_managers/Transform2DComponentManager.hpp"
#include "component_managers/NameComponentManager.hpp"
#include "component_managers/MeshComponentManager.hpp"
#include "component_managers/SpriteDrawableComponentManager.hpp"

#include "components/SpriteDrawableComponent.hpp"


#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <cstdio>

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

    EntityManager entity_manager;

    Transform2DComponentManager transform_2D_component_manager;
    NameComponentManager name_component_manager;
    MeshComponentManager mesh_component_manager;
    SpriteDrawableComponentManager sprite_drawable_component_manager;

    MeshFactory mesh_factory;
    Mesh flat_mesh = mesh_factory.createFlatMesh();
    shared_ptr<Mesh> flat_mesh_ptr = make_shared<Mesh>(flat_mesh);

    float aspect_ratio = viewport.getAspectRatio();

    Entity entity_a = entity_manager.create();
    transform_2D_component_manager.setTransform(entity_a, Transform2D(glm::vec2(0.1, 0.1 * aspect_ratio), glm::vec2(0, 0)));
    mesh_component_manager.setMesh(entity_a, flat_mesh_ptr);
    name_component_manager.setName(entity_a, "Snorlax");
    sprite_drawable_component_manager.setSpriteDrawableComponent(entity_a, SpriteDrawableComponent(Texture::createFromFile("res/snorlax.png")));

    Entity entity_b = entity_manager.create();
    transform_2D_component_manager.setTransform(entity_b, Transform2D(glm::vec2(0.1, 0.1 * aspect_ratio), glm::vec2(0.5, 0)));
    mesh_component_manager.setMesh(entity_b, flat_mesh_ptr);
    name_component_manager.setName(entity_b, "Gengar");
    sprite_drawable_component_manager.setSpriteDrawableComponent(entity_b, SpriteDrawableComponent(Texture::createFromFile("res/gengar.png")));

    Entity entity_c = entity_manager.create();
    transform_2D_component_manager.setTransform(entity_c, Transform2D(glm::vec2(0.1, 0.1 * aspect_ratio), glm::vec2(-0.5, 0)));
    mesh_component_manager.setMesh(entity_c, flat_mesh_ptr);
    name_component_manager.setName(entity_c, "Eevee");
    sprite_drawable_component_manager.setSpriteDrawableComponent(entity_c, SpriteDrawableComponent(Texture::createFromFile("res/eevee.png")));

    // Display loop
    while(window.isOpen()) {
        window.clearBuffers();
        handleInputs(window);

        sprite_drawable_component_manager.update(transform_2D_component_manager, mesh_component_manager);

        window.display();
    }

    // Close the window
    window.close();

    // Nothing went wrong!
    return 0;
}
