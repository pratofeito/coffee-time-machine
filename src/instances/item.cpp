#include "instances/item.hpp"

Item::Item(std::string name, int x, int y, int i) : Instance(x, y)
{
    item_name = name;
    holding_item = false;

    hit_box.setFillColor(sf::Color(255, 165, 0));
    hit_box.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    hit_box.setPosition(virtual_position.x * GRID_SIZE, virtual_position.y * GRID_SIZE);
    item_collision = new Collision(this);
    this->i = i;
}

Item::~Item()
{
}

bool Item::get_holding()
{
    return this->holding_item;
}

std::string Item::get_name()
{
    return this->item_name;
}

bool Item::instance_interact()
{
    return 0;
}

void Item::instance_interact(std::map<const std::string, bool> &bag)
{
    //  Chamar o dialogo do item caso a opção seja pegar executa a próxima linha:
    holding_item = true;
    item_collision->disable_collision();

    // Resolvido da mesma forma que em L01E06 - FOLHA SALARIAL asjdklajdlkasldjask
    bag.insert(std::pair<std::string, bool>(this->item_name, true));
    bag[item_name] = true;

    carrot_sprite.setFillColor(sf::Color(255, 165, 0));
    carrot_sprite.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    carrot_sprite.setPosition((1 + i) * GRID_SIZE, 1 * GRID_SIZE);
}

void Item::instance_draw(sf::RenderTarget *target)
{
    std::cout << "BBBBBBBBBBBBBB" << this->given;

    if (holding_item == false)
    {
        target->draw(this->hit_box);
    }
    if (holding_item == true)
    {
        if (given == false)
        {
            std::cout << "trueee" << this->given << std::endl;
            target->draw(this->carrot_sprite);
        }
        if (given == true)
        {
            std::cout << "false" << this->given << std::endl;
            target->draw(this->carrot_sprite);
            carrot_sprite.setFillColor(sf::Color::Transparent);
        }
    }
}
void Item::instance_update(const float &delta_time)
{
    // Eu tive uma ideia que funcionava (gambiarra)
    // Get setter ponteiro pro item o player olha (acessar as info de iten/npc)
    // Ver como isso se relacionaria com a janela
}

void Item::set_given(bool aqui)
{
    this->given = aqui;
    std::cout << "AAAAAAA" << this->given << aqui;
}
