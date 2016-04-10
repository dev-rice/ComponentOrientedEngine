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

void SpriteDrawableComponentManager::update(MeshComponentManager& mesh_component_manager) {

    for (auto& entity: entities) {
        Mesh& mesh = mesh_component_manager.getMesh(entity);
        FlatDrawable flat_drawable(mesh, flat_shader);
        Transform2D flat_transform;
        flat_transform.setScale(glm::vec2(0.5, 0.5));

        flat_drawable.draw(flat_transform);

    }

}
