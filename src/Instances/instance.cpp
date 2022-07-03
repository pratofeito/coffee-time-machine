
#include "Instances/instance.hpp"

Instance::Instance()
{
    this->colision_mask.setSize(sf::Vector2f(32.f, 32.f));
    this->colision_mask.setOrigin(sf::Vector2f(0.f, 0.f));
    this->colision_mask.setFillColor(sf::Color::Magenta);
    this->speed = 200.f;
}

Instance::~Instance()
{
}

void Instance::instance_move(const float delta_time, float dir_x, float dir_y)
{
    this->colision_mask.move(dir_x * this->speed * delta_time, dir_y * this->speed * delta_time);
}

void Instance::instance_draw(sf::RenderTarget *target)
{
    target->draw(this->colision_mask);
}

void Instance::instance_update(const float &delta_time)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->instance_move(delta_time, 0.f, -1.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->instance_move(delta_time, 0.f, 1.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->instance_move(delta_time, -1.f, 0.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->instance_move(delta_time, 1.f, 0.f);
    }
}