#include "Scene.hpp"

#include "Entity.hpp"
#include "FlatDrawable.hpp"
#include "Texture.hpp"

#include "components/SpriteDrawableComponent.hpp"

Scene::Scene(float aspect_ratio) : aspect_ratio(aspect_ratio) {

    Entity background = entity_manager.create();
    transform_2D_component_manager.setTransform(background, Transform2D(glm::vec2(1.0, 1.0), glm::vec2(0, 0)));
    name_component_manager.setName(background, "Background");
    sprite_drawable_component_manager.setSpriteDrawableComponent(background, SpriteDrawableComponent(Texture::createFromColor(glm::vec4(0.9, 0.9, 0.9, 1.0))));

    Entity entity_a = entity_manager.create();
    transform_2D_component_manager.setTransform(entity_a, Transform2D(glm::vec2(0.1, 0.1 * aspect_ratio), glm::vec2(0, 0)));
    name_component_manager.setName(entity_a, "Snorlax");
    sprite_drawable_component_manager.setSpriteDrawableComponent(entity_a, SpriteDrawableComponent(Texture::createFromFile("res/snorlax.png")));

    Entity entity_b = entity_manager.create();
    transform_2D_component_manager.setTransform(entity_b, Transform2D(glm::vec2(0.1, 0.1 * aspect_ratio), glm::vec2(0.5, 0)));
    name_component_manager.setName(entity_b, "Gengar");
    sprite_drawable_component_manager.setSpriteDrawableComponent(entity_b, SpriteDrawableComponent(Texture::createFromFile("res/gengar.png")));

    Entity entity_c = entity_manager.create();
    transform_2D_component_manager.setTransform(entity_c, Transform2D(glm::vec2(0.1, 0.1 * aspect_ratio), glm::vec2(-0.5, 0)));
    name_component_manager.setName(entity_c, "Eevee");
    sprite_drawable_component_manager.setSpriteDrawableComponent(entity_c, SpriteDrawableComponent(Texture::createFromFile("res/eevee.png")));


}

void Scene::update() {
    sprite_drawable_component_manager.update(transform_2D_component_manager, mesh_component_manager, name_component_manager);
}
