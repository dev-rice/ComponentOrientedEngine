#ifndef Transform2DComponentManager_h
#define Transform2DComponentManager_h

#include <map>

#include "Entity.hpp"
#include "Transform2D.hpp"

class Transform2DComponentManager {
public:
    void setTransform(Entity e, Transform2D transform);
    Transform2D getTransform(Entity e);
private:
    std::map<Entity, Transform2D> entity_transform_map;

};

#endif
