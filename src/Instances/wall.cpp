#include "Instances/wall.hpp"

Wall::Wall()
{
    // this->colision_mask.setFillColor(sf::Color::White);
    this->colision_mask.setPosition(GRID_SIZE * 5, GRID_SIZE * 2);
}

Wall::~Wall()
{
}

sf::RectangleShape Wall::get_colision_mask()
{
    return this->colision_mask;
}

void Wall::set_color(sf::Color color)
{
    this->colision_mask.setFillColor(color);
}

void Wall::instance_draw(sf::RenderTarget *target)
{
    target->draw(this->colision_mask);
}

void Wall::instance_update(const float &delta_time)
{
}