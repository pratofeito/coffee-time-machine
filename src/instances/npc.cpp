#include "instances/npc.hpp"

Npc::Npc(std::string name, int x, int y, std::string script) : Instance(x, y)
{
    hit_box.setFillColor(sf::Color::Yellow);
    hit_box.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    hit_box.setPosition(virtual_position.x * GRID_SIZE, virtual_position.y * GRID_SIZE);

    this->name = name;
    npc_collision = new Collision(this);
    npc_dialogue = new Dialogue(script);

    // default states and looking
    instance_state = NOTHING;
    looking = RIGHT;

    // animation and default animation defined
    npc_animation = new Animation(this);
    npc_animation->new_state(-2, -2, "resources/sprites/demo/player_idle.png");
    npc_sprite = npc_animation->get_sprite();

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
    // target->draw(this->hit_box);
    target->draw(*this->npc_sprite);
}

void Npc::instance_update(const float &delta_time)
{
    this->projected_position = sf::Vector2f(virtual_position.x * TILE_SIZE, virtual_position.y * TILE_SIZE);
    npc_animation->update(instance_state, looking, delta_time);
    npc_sprite->setPosition(projected_position);
    // npc_sprite = npc_animation->get_sprite();}
}

Dialogue *Npc::get_npc_dialogue()
{
    return npc_dialogue;
}

void Npc::set_looking(int direction) {
    this->looking = direction;
}
