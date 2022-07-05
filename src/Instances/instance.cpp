
#include "Instances/instance.hpp"

Instance::Instance()
{
    this->colision_mask.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    this->colision_mask.setOrigin(sf::Vector2f(0.f, 0.f));
}

Instance::~Instance()
{
}