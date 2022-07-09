#include "instances/item.hpp"

Item::Item(std::string name, int x, int y) : Instance(x, y)
{
    item_name = name;
    holding_item = false;

    hit_box.setFillColor(sf::Color(255, 165, 0));
    hit_box.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    hit_box.setPosition(virtual_position.x * GRID_SIZE, virtual_position.y * GRID_SIZE);
    item_collision = new Collision(this);
}

Item::~Item()
{
    // Provavelmente vai ser chamado quando o item for iteragido
}

void Item::set_holding(bool value)
{
    this->holding_item = value;
}
bool Item::get_holding()
{
    return this->holding_item;
}
void Item::instance_interact()
{
    std::cout << "Interagiu com: " << this->item_name << std::endl;
    // Chamar o dialogo do item caso a opção seja pegar executa a próxima linha:
    holding_item = true;
    item_collision->disable_collision();
}
void Item::instance_draw(sf::RenderTarget *target)
{
    if (holding_item == false)
    {
        target->draw(this->hit_box);
    }
}
void Item::instance_update(const float &delta_time)
{
}