#ifndef Scene_h
#define Scene_h

#include <memory>

#include "Mesh.hpp"

#include "EntityManager.hpp"
#include "component_managers/Transform2DComponentManager.hpp"
#include "component_managers/NameComponentManager.hpp"
#include "component_managers/MeshComponentManager.hpp"
#include "component_managers/SpriteDrawableComponentManager.hpp"

class Scene {
public:
    Scene(float aspect_ratio, shared_ptr<Mesh> flat_mesh_ptr);
    void update();

private:
    EntityManager entity_manager;

    Transform2DComponentManager transform_2D_component_manager;
    NameComponentManager name_component_manager;
    MeshComponentManager mesh_component_manager;
    SpriteDrawableComponentManager sprite_drawable_component_manager;

    float aspect_ratio;
    shared_ptr<Mesh> flat_mesh_ptr;

};

#endif
