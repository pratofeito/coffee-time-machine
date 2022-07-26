#include "instances/wall.hpp"

Wall::Wall(int x, int y) : Instance(x, y)
{
    hit_box.setFillColor(sf::Color::Transparent);
    hit_box.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    hit_box.setPosition(virtual_position.x * GRID_SIZE, virtual_position.y * GRID_SIZE);

    // Inicializa a wall_collision colocando ela no vetor de colisões
    wall_collision = new Collision(this);
}

Wall::~Wall()
{
    delete wall_collision;
}

bool Wall::instance_interact()
{
    return 0;
}

void Wall::instance_draw(sf::RenderTarget *target)
{
    target->draw(this->hit_box);
}

void Wall::instance_update(const float &delta_time)
{
}