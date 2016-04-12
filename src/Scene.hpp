#ifndef Scene_h
#define Scene_h

#include <memory>

#include "includes/json.hpp"

#include "Mesh.hpp"

#include "EntityManager.hpp"
#include "component_managers/Transform2DComponentManager.hpp"
#include "component_managers/NameComponentManager.hpp"
#include "component_managers/MeshComponentManager.hpp"
#include "component_managers/SpriteDrawableComponentManager.hpp"

class Scene {
public:
    static Scene fromFile(string filename);

    void update();

private:
    Scene(float aspect_ratio, string filename);

    // Functions for file parsing
    void handleTransform2DComponent(Json::Value entity_json, Entity entity);
    void handleNameComponent(Json::Value entity_json, Entity entity);
    void handleSpriteDrawableComponent(Json::Value entity_json, Entity entity);

    EntityManager entity_manager;

    Transform2DComponentManager transform_2D_component_manager;
    NameComponentManager name_component_manager;
    MeshComponentManager mesh_component_manager;
    SpriteDrawableComponentManager sprite_drawable_component_manager;

    float aspect_ratio;

};

#endif
