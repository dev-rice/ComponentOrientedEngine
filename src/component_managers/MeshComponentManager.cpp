#include "MeshComponentManager.hpp"

void MeshComponentManager::setMesh(Entity entity, shared_ptr<Mesh> mesh) {
    entity_to_mesh_map[entity] = mesh;
}

Mesh& MeshComponentManager::getMesh(Entity entity) {
    return *entity_to_mesh_map[entity];
}
