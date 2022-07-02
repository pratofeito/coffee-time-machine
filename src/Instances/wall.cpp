#include "Instances/wall.hpp"

Wall::Wall()
{
    this->colision_mask.setFillColor(sf::Color::White);
    this->colision_mask.setPosition(GRID_SIZE * 5, GRID_SIZE * 2);
}

Wall::~Wall()
{
}

void Wall::instance_draw(sf::RenderTarget *target)
{
    target->draw(this->colision_mask);
}

void Wall::instance_update(const float &delta_time)
{
}