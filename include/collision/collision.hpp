#ifndef COLLISION_H
#define COLLISION_H

#include "instances/instance.hpp"
#include <list>

class Collision
{
private:
    static std::list<Instance *> collidable;
    Instance *collidable_instance;

public:
    Instance *get_collision(sf::Vector2i position);

    Collision(Instance *new_object);
    virtual ~Collision();
    virtual void disable_collision();
};

#endif