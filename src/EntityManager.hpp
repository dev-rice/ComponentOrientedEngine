#ifndef EntityManager_h
#define EntityManager_h

#include <set>

#include "Entity.hpp"

class EntityManager {
public:
    Entity create();
    bool alive(Entity e);
    void destroy(Entity e);

private:
    std::set<Entity> entities;
    Entity next;

};

#endif
