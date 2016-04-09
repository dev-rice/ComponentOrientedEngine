#ifndef NameComponentManager_h
#define NameComponentManager_h

#include <string>
#include <map>

#include "Entity.hpp"

class NameComponentManager {
public:
    void setName(Entity e, std::string name);
    std::string getName(Entity entity);

private:
    std::string getDefaultName();
    std::map<Entity, std::string> name_component_map;
};

#endif
