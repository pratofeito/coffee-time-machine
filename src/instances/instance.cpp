
#include "instances/instance.hpp"

Instance::Instance(int x, int y)
{
    this->virtual_position = sf::Vector2i(x, y);
}

Instance::~Instance()
{
}