#include "NameComponentManager.hpp"

void NameComponentManager::setName(Entity entity, std::string name) {
    name_component_map[entity] = name;
}

std::string NameComponentManager::getName(Entity entity) {
    if(name_component_map.find(entity) != name_component_map.end()) {
        return name_component_map[entity];
    } else {
        return getDefaultName();
    }
}

std::string NameComponentManager::getDefaultName() {
    return "Entity";
}
