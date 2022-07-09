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
    Dialogue item_dialogue;
    bool holding_item;

public:
    Item(std::string name, int x, int y);
    virtual ~Item();

    void set_holding(bool value);
    bool get_holding();

    virtual void instance_desinteract() override;
    virtual void instance_interact() override;
    virtual void instance_draw(sf::RenderTarget *target) override;
    virtual void instance_update(const float &delta_time) override;
};

#endif