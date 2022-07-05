#ifndef COLLISION_H
#define COLLISION_H

#include "instances/instance.hpp"

class Collision
{
private:
    static std::vector<Instance *> collidable;

public:
    Instance *get_collision(sf::Vector2i position);

    Collision(Instance *new_object);
    ~Collision();
};

#endif