#include "Scene.hpp"

#include <iostream>
#include <fstream>

#include "includes/json.hpp"

#include "Entity.hpp"
#include "FlatDrawable.hpp"
#include "Texture.hpp"

#include "components/SpriteDrawableComponent.hpp"

using namespace std;

Scene::Scene(Viewport viewport, string filename) : viewport(viewport) {

    string json_contents = getFileContentsAsString(filename);
    buildSceneFromJSONContents(json_contents);

}

Scene Scene::fromFile(Viewport viewport, string filename) {
    return Scene(viewport, filename);
}

void Scene::update() {
    glViewport(0, 0, viewport.getWidth(), viewport.getHeight());
    sprite_drawable_component_manager.update(transform_2D_component_manager, mesh_component_manager, name_component_manager);
}

string Scene::getFileContentsAsString(string filename) {
    ifstream scene_input(filename);
    if (!scene_input) {
        cout << "Failed to open file " << filename << "\n";
    }
    string scene_file_contents((istreambuf_iterator<char>(scene_input)), istreambuf_iterator<char>());
    scene_input.close();

    return scene_file_contents;
}

void Scene::buildSceneFromJSONContents(string scene_json_contents) {
    Json::Value root;
    Json::Reader reader;

    bool parsing_successful = reader.parse(scene_json_contents, root);
    if (!parsing_successful){
        cout << "Failed to parse scene file\n" << reader.getFormattedErrorMessages();
    }

    loadAllEntitiesFromJSON(root);

}

void Scene::loadAllEntitiesFromJSON(Json::Value root) {
    Json::Value entities_json = root["entities"];
    for (auto& entity_json : entities_json) {
        Entity entity = entity_manager.create();

        if (entity_json.isMember("Transform2DComponent")) {
            handleTransform2DComponent(entity_json, entity);
        }

        if (entity_json.isMember("NameComponent")) {
            handleNameComponent(entity_json, entity);
        }

        if (entity_json.isMember("SpriteDrawableComponent")) {
            handleSpriteDrawableComponent(entity_json, entity);
        }

    }
}

void Scene::handleTransform2DComponent(Json::Value entity_json, Entity entity) {

    Json::Value transform2D_json = entity_json["Transform2DComponent"];

    float aspect_ratio = viewport.getAspectRatio();

    glm::vec2 scale(
        transform2D_json["scale_x"].asFloat(),
        transform2D_json["scale_y"].asFloat() * aspect_ratio);

    glm::vec2 position(
        transform2D_json["position_x"].asFloat(),
        transform2D_json["position_y"].asFloat());

    Transform2D transform2D(scale, position);
    transform_2D_component_manager.setTransform(entity, transform2D);
}

void Scene::handleNameComponent(Json::Value entity_json, Entity entity) {
    Json::Value name_component_json = entity_json["NameComponent"];
    string name = name_component_json["name"].asString();
    name_component_manager.setName(entity, name);
}

void Scene::handleSpriteDrawableComponent(Json::Value entity_json, Entity entity) {

    Json::Value sprite_drawable_component_json = entity_json["SpriteDrawableComponent"];

    if (sprite_drawable_component_json.isMember("sprite")) {
        string sprite_filename = sprite_drawable_component_json["sprite"].asString();
        Texture sprite_texture = Texture::createFromFile(sprite_filename);
        sprite_drawable_component_manager.setSpriteDrawableComponent(entity, SpriteDrawableComponent(sprite_texture));

    } else if (sprite_drawable_component_json.isMember("color")) {
        Json::Value sprite_color_json = sprite_drawable_component_json["color"];
        glm::vec4 sprite_color(
            sprite_color_json["red"].asFloat(),
            sprite_color_json["green"].asFloat(),
            sprite_color_json["blue"].asFloat(),
            sprite_color_json["alpha"].asFloat()
        );
        sprite_drawable_component_manager.setSpriteDrawableComponent(entity, SpriteDrawableComponent(Texture::createFromColor(sprite_color)));

    }

}
