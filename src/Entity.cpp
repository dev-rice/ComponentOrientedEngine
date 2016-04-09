#include "Entity.hpp"

bool operator==(const Entity a, const Entity b) {
    return a.id == b.id;
}

bool operator<(const Entity a, const Entity b) {
    return a.id < b.id;
}
