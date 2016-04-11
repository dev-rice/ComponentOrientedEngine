#include "SpriteDrawableComponentManager.hpp"

#include "FlatDrawable.hpp"
#include "Transform2D.hpp"

void SpriteDrawableComponentManager::setSpriteDrawableComponent(Entity entity, SpriteDrawableComponent sprite_drawable_component) {

    entity_sprite_drawable_component_map[entity] = sprite_drawable_component;
}

SpriteDrawableComponent& SpriteDrawableComponentManager::getSpriteDrawableComponent(Entity entity) {

    return entity_sprite_drawable_component_map[entity];
}

void SpriteDrawableComponentManager::update(Transform2DComponentManager& transform_2D_component_manager, MeshComponentManager& mesh_component_manager) {

    for (auto& key_value: entity_sprite_drawable_component_map) {
        Entity entity = key_value.first;
        Mesh& entity_mesh = mesh_component_manager.getMesh(entity);
        Transform2D& entity_transform_2D = transform_2D_component_manager.getTransform(entity);
        getSpriteDrawableComponent(entity).draw(entity_mesh, entity_transform_2D);



    }

}
