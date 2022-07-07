#include "collision/collision.hpp"

std::vector<Instance *> Collision::collidable;
Collision::Collision(Instance *new_object)
{
    this->collidable.push_back(new_object);
}

Collision::~Collision()
{
}

Instance *Collision::get_collision(sf::Vector2i position)
{
    for (auto instance : collidable)
    {
        if (instance->virtual_position == position)
        {
            return instance;
        }
    }
    return nullptr;
}
