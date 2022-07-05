#ifndef COLLISION_H
#define COLLISION_H

#include "instance.hpp"

class Collision
{
private:
    static std::vector<Instance *> collidable;

public:
    Collision();
    ~Collision();
};

#endif