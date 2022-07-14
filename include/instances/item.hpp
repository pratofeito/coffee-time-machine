#ifndef ITEM_H
#define ITEM_H

#include "collision/collision.hpp"
#include "dialogue/dialogue.hpp"

class Item : public Instance
{
private:
    std::string item_name;
    Collision *item_collision;
    sf::RectangleShape hit_box;
    // Substituir pro icone que vai ser desenhado
    // sf::RectangleShape carrot_sprite;

    Dialogue item_dialogue;
    bool holding_item;
    int i;

    sf::Texture *spr_texture;
    sf::Sprite *spr_item;

    sf::Texture *spr_texture_icon;
    sf::Sprite *spr_item_icon;


public:
    bool given;
    sf::RectangleShape carrot_sprite;

    Item(std::string name, int x, int y, int i, std::string spr_dir, std::string spr_dir_icon);
    virtual ~Item();

    bool get_holding();
    void set_given(bool given_item);

    std::string get_name();

    virtual bool instance_interact() override;
    virtual void instance_interact(std::map<const std::string, bool> &bag) override;
    virtual void instance_draw(sf::RenderTarget *target) override;
    virtual void instance_update(const float &delta_time) override;
};

#endif