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

#include "Viewport.hpp"

using namespace std;

class Scene {
public:
    static Scene fromFile(Viewport viewport, string filename);

    void update();

private:
    Scene(Viewport viewport, string filename);

    // Functions for file parsing
    bool hasComponent(Json::Value entity_json, string component_name);

    string getFileContentsAsString(string filename);
    void buildSceneFromJSONContents(string json_contents);

    void loadRenderingViewportFromJSON(Json::Value root);
    void loadAllEntitiesFromJSON(Json::Value root);

    void handleTransform2DComponent(Json::Value entity_json, Entity entity);
    void handleNameComponent(Json::Value entity_json, Entity entity);
    void handleSpriteDrawableComponent(Json::Value entity_json, Entity entity);

    EntityManager entity_manager;

    Transform2DComponentManager transform_2D_component_manager;
    NameComponentManager name_component_manager;
    MeshComponentManager mesh_component_manager;
    SpriteDrawableComponentManager sprite_drawable_component_manager;

    Viewport viewport;

    float aspect_ratio;

};

#endif
