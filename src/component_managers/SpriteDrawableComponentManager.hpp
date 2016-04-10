#ifndef SpriteDrawableComponentManager_h
#define SpriteDrawableComponentManager_h

#include "ShaderProgram.hpp"

#include "component_managers/MeshComponentManager.hpp"
#include "component_managers/Transform2DComponentManager.hpp"


class SpriteDrawableComponentManager {
public:
    SpriteDrawableComponentManager();
    void registerEntity(Entity e);
    void update(Transform2DComponentManager& transform_2D_component_manager, MeshComponentManager& mesh_component_manager);
private:
    ShaderProgram flat_shader;
    vector<Entity> entities;

};

#endif
