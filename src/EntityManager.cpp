#include "EntityManager.hpp"

Entity EntityManager::create() {
    ++next.id;
    while (alive(next)){
        ++next.id;
    }
    entities.insert(next);
    return next;
}

bool EntityManager::alive(Entity entity) {
    return entities.find(entity) != entities.end();
}

void EntityManager::destroy(Entity entity) {
    entities.erase(entity);
}
