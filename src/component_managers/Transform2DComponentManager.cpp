#include "Transform2DComponentManager.hpp"

void Transform2DComponentManager::setTransform(Entity entity, Transform2D transform) {

    entity_transform_map[entity] = transform;
}

Transform2D& Transform2DComponentManager::getTransform(Entity entity) {
    if(entity_transform_map.find(entity) == entity_transform_map.end()) {
        entity_transform_map[entity] = Transform2D();
    }
    return entity_transform_map[entity];

}
