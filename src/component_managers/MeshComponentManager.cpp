#include "MeshComponentManager.hpp"

#include "MeshFactory.hpp"


MeshComponentManager::MeshComponentManager(): flat_mesh(MeshFactory::createFlatMesh()) {

}

Mesh& MeshComponentManager::getMesh(Entity entity) {
    return flat_mesh;
}
