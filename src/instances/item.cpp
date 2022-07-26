#include "instances/item.hpp"

Item::Item(std::string name, int x, int y, int i, std::string spr_dir, std::string spr_dir_icon) : Instance(x, y)
{
    item_name = name;
    holding_item = false;

    hit_box.setFillColor(sf::Color::Transparent);
    hit_box.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    hit_box.setPosition(virtual_position.x * GRID_SIZE, virtual_position.y * GRID_SIZE);
    item_collision = new Collision(this);
    this->i = i;
    this->x = x;
    this->y = x;

    // textura item pequeno
    spr_texture = new sf::Texture();
    spr_texture->loadFromFile(spr_dir);
    spr_item = new sf::Sprite();
    spr_item->setTexture(*spr_texture);
    spr_item->setPosition(sf::Vector2f(x * GRID_SIZE, y * GRID_SIZE));

    // textura item grande
    spr_texture_icon = new sf::Texture();
    spr_texture_icon->loadFromFile(spr_dir_icon);
    spr_item_icon = new sf::Sprite();
    spr_item_icon->setTexture(*spr_texture_icon);
    spr_item_icon->setPosition(sf::Vector2f(x * GRID_SIZE, y * GRID_SIZE));
}

Item::~Item()
{
    delete spr_item;
    delete spr_texture;
    delete spr_item_icon;
    delete spr_texture_icon;
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
    spr_item_icon->setPosition((1 + i) * GRID_SIZE, 1 * GRID_SIZE);
}

void Item::instance_draw(sf::RenderTarget *target)
{
    // temporariamente desabilitado
    if (holding_item == false)
    {
        // target->draw(this->hit_box);
        target->draw(*this->spr_item);
    }
    if (holding_item == true)
    {
        if (given == false)
        {
            // target->draw(this->carrot_sprite);
            // target->draw(*this->spr_item_icon);
        }
        if (given == true)
        {
            // target->draw(this->carrot_sprite);
            // carrot_sprite.setFillColor(sf::Color::Transparent);
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
}
