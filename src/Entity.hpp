#ifndef Entity_h
#define Entity_h

struct Entity {
    unsigned id;
};

bool operator==(const Entity a, const Entity b);
bool operator<(const Entity a, const Entity b);

#endif
