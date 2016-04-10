#include "SpriteDrawableComponentManager.hpp"

#include "ShaderProgramFactory.hpp"
#include "FlatDrawable.hpp"
#include "Transform2D.hpp"

SpriteDrawableComponentManager::SpriteDrawableComponentManager() {
    flat_shader = ShaderProgramFactory::createShaderProgram("shaders/flat.vs", "shaders/flat.fs");
}

void SpriteDrawableComponentManager::registerEntity(Entity entity) {
    entities.push_back(entity);
}

void SpriteDrawableComponentManager::update(Transform2DComponentManager& transform_2D_component_manager, MeshComponentManager& mesh_component_manager) {

    for (auto& entity: entities) {
        Mesh& entity_mesh = mesh_component_manager.getMesh(entity);
        Transform2D& entity_transform_2D = transform_2D_component_manager.getTransform(entity);

        FlatDrawable flat_drawable(entity_mesh, flat_shader);
        flat_drawable.draw(entity_transform_2D);

    }

}
