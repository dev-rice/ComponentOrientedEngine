#include "MeshComponentManager.hpp"

MeshComponentManager::MeshComponentManager() {
    ShaderProgramFactory shader_program_factory;
    flat_shader = shader_program_factory.createShaderProgram("shaders/flat.vs", "shaders/flat.fs");
}

void MeshComponentManager::setMesh(Entity entity, shared_ptr<Mesh> mesh) {
    entity_to_mesh_map[entity] = mesh;
}

Mesh& MeshComponentManager::getMesh(Entity entity) {
    return *entity_to_mesh_map[entity];
}

void MeshComponentManager::update() {
    for (auto& entity: entity_to_mesh_map) {
        Mesh& mesh = *entity.second;
        FlatDrawable flat_drawable(mesh, flat_shader);
        Transform2D flat_transform;
        flat_transform.setScale(glm::vec2(0.5, 0.5));

        flat_drawable.draw(flat_transform);

    }

}
