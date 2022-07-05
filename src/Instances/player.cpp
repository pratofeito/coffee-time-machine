#include "Instances/player.hpp"

Player::Player()
{
    this->colision_mask.setFillColor(sf::Color::Cyan);
}

Player::~Player()
{
}

void Player::player_move(const float delta_time)
{
    x += velh;
    y += velv;
    colision_mask.setPosition(this->x, this->y);
}

void Player::player_inputs()
{
    // Movimentos
    bool up = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    bool down = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

    if (up || down || left || right)
    {
        velv = move_speed * (down - up);
        velh = move_speed * (right - left);
    }
    else
    {
        velv = 0;
        velh = 0;
    }
}

void Player::instance_draw(sf::RenderTarget *target)
{
    target->draw(this->colision_mask);
}

void Player::instance_update(const float &delta_time)
{
    player_inputs();
    player_move(delta_time);
}