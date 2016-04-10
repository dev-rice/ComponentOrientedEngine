#ifndef SpriteDrawableComponentManager_h
#define SpriteDrawableComponentManager_h

#include "ShaderProgram.hpp"

#include "MeshComponentManager.hpp"

class SpriteDrawableComponentManager {
public:
    SpriteDrawableComponentManager();
    void registerEntity(Entity e);
    void update(MeshComponentManager& mesh_component_manager);
private:
    ShaderProgram flat_shader;
    vector<Entity> entities;

};

#endif
