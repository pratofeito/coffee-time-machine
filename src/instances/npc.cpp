#include "instances/npc.hpp"

Npc::Npc(std::string name, int x, int y, std::string script) : Instance(x, y)
{
    hit_box.setFillColor(sf::Color::Yellow);
    hit_box.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    hit_box.setPosition(virtual_position.x * GRID_SIZE, virtual_position.y * GRID_SIZE);
    this->name = name;
    npc_collision = new Collision(this);
    npc_dialogue = new Dialogue(script);
}

Npc::~Npc()
{
    delete npc_dialogue;
    delete npc_collision;
}

bool Npc::instance_interact()
{
    npc_dialogue->interacted = true;
    return npc_dialogue->get_on_going();
}

void Npc::instance_draw(sf::RenderTarget *target)
{
    target->draw(this->hit_box);
}

void Npc::instance_update(const float &delta_time)
{
}

Dialogue *Npc::get_npc_dialogue()
{
    return npc_dialogue;
}
