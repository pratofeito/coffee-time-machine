#include "instances/wall.hpp"

Wall::Wall(int x, int y) : Instance(x, y)
{
    hit_box.setFillColor(sf::Color::Cyan);
    hit_box.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    hit_box.setPosition(virtual_position.x * GRID_SIZE, virtual_position.y * GRID_SIZE);

    // Inicializa a wall_collision colocando ela no vetor de colisões
    wall_collision = new Collision(this);
}

Wall::~Wall()
{
    delete wall_collision;
}

void Wall::instance_desinteract()
{
}

void Wall::instance_interact()
{
    this->hit_box.setFillColor(sf::Color::Red);
    std::cout << "Interagiu" << std::endl;
}

void Wall::instance_draw(sf::RenderTarget *target)
{
    target->draw(this->hit_box);
}

void Wall::instance_update(const float &delta_time)
{
}