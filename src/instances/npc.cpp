#include "instances/npc.hpp"

Npc::Npc(std::string name, int x, int y) : Instance(x, y)
{
    hit_box.setFillColor(sf::Color::Yellow);
    hit_box.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    hit_box.setPosition(virtual_position.x * GRID_SIZE, virtual_position.y * GRID_SIZE);

    this->name = name;
    npc_collision = new Collision(this);
}

Npc::~Npc()
{
    delete npc_collision;
}

void Npc::instance_interact()
{
    std::cout << "Interagiu com: " << this->name << std::endl;
}

void Npc::instance_draw(sf::RenderTarget *target)
{
    target->draw(this->hit_box);
}

void Npc::instance_update(const float &delta_time)
{
}