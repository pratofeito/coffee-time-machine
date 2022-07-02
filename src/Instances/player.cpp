#include "Instances/player.hpp"

Player::Player()
{
    this->colision_mask.setFillColor(sf::Color::Cyan);
    walking = false;
    for (int i = 0; i < 4; i++)
    {
        move[i] = false;
    }
}

Player::~Player()
{
}

void Player::player_move(const float delta_time)
{
    if (move[DOWN] == true)
    {
        this->y += move_speed + delta_time;
        if (this->y >= next_tile)
        {
            this->y = next_tile;
            walking = false;
            move[DOWN] = false;
        }
    }

    if (move[UP] == true)
    {
        this->y -= move_speed - delta_time;
        if (this->y <= next_tile)
        {
            this->y = next_tile;
            walking = false;
            move[UP] = false;
        }
    }

    if (move[LEFT] == true)
    {
        this->x -= move_speed - delta_time;
        if (this->x <= next_tile)
        {
            this->x = next_tile;
            walking = false;
            move[LEFT] = false;
        }
    }

    if (move[RIGHT] == true)
    {
        this->x += move_speed + delta_time;
        if (this->x >= next_tile)
        {
            this->x = next_tile;
            walking = false;
            move[RIGHT] = false;
        }
    }
    colision_mask.setPosition(this->x, this->y);
}

void Player::player_inputs()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (walking == false)
        {
            next_tile = y - GRID_SIZE;
            move[UP] = true;
            walking = true;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        // this->player_move(delta_time, 0.f, 1.f);
        if (walking == false)
        {
            next_tile = y + GRID_SIZE;
            move[DOWN] = true;
            walking = true;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        // this->player_move(delta_time, -1.f, 0.f);
        if (walking == false)
        {
            next_tile = x - GRID_SIZE;
            move[LEFT] = true;
            walking = true;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        // this->player_move(delta_time, 1.f, 0.f);
        if (walking == false)
        {
            next_tile = x + GRID_SIZE;
            move[RIGHT] = true;
            walking = true;
        }
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