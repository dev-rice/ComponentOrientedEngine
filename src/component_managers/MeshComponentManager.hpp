#ifndef MeshComponentManager_h
#define MeshComponentManager_h

#include <string>
#include <memory>
#include <map>

#include "Entity.hpp"
#include "Mesh.hpp"

#include "ShaderProgram.hpp"
#include "ShaderProgramFactory.hpp"

#include "FlatDrawable.hpp"
#include "Transform2D.hpp"

class MeshComponentManager {
public:
    MeshComponentManager();
    void setMesh(Entity entity, shared_ptr<Mesh> mesh);
    Mesh& getMesh(Entity entity);

    void update();

private:
    std::map<Entity, shared_ptr<Mesh>> entity_to_mesh_map;
    ShaderProgram flat_shader;

};

#endif
