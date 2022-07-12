#ifndef ITEM_H
#define ITEM_H

#include "collision/collision.hpp"
#include "instances/dialogue/dialogue.hpp"

class Item : public Instance
{
private:
    std::string item_name;
    Collision *item_collision;
    sf::RectangleShape hit_box;
    // Substituir pro icone que vai ser desenhado
    sf::RectangleShape carrot_sprite;

    Dialogue item_dialogue;
    bool holding_item;

public:
    Item(std::string name, int x, int y);
    virtual ~Item();

    bool get_holding();

    std::string get_name();

    virtual void instance_interact() override;
    virtual void instance_interact(std::map<const std::string, bool> &bag) override;
    virtual void instance_draw(sf::RenderTarget *target) override;
    virtual void instance_update(const float &delta_time) override;
};

#endif