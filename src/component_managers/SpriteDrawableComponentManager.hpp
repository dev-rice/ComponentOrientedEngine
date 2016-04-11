#ifndef SpriteDrawableComponentManager_h
#define SpriteDrawableComponentManager_h

#include "ShaderProgram.hpp"

#include "component_managers/NameComponentManager.hpp"
#include "component_managers/MeshComponentManager.hpp"
#include "component_managers/Transform2DComponentManager.hpp"

#include "components/SpriteDrawableComponent.hpp"

class SpriteDrawableComponentManager {
public:
    void setSpriteDrawableComponent(Entity entity, SpriteDrawableComponent sprite_drawable_component);
    SpriteDrawableComponent& getSpriteDrawableComponent(Entity entity);
    void update(Transform2DComponentManager& transform_2D_component_manager, MeshComponentManager& mesh_component_manager, NameComponentManager& name_component_managerr);
private:
    map<Entity, SpriteDrawableComponent> entity_sprite_drawable_component_map;

};

#endif
