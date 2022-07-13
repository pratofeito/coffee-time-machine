#include "instances/instance.hpp"

Instance::Instance(int x, int y)
{
    this->virtual_position = sf::Vector2i(x, y);
    interact_status = false;
}

Instance::~Instance()
{
}

bool Instance::get_interact_status()
{
    return this->interact_status;
}