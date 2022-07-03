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
        if (this->y >= next_tile_y)
        {
            this->y = next_tile_y;
            walking = false;
            move[DOWN] = false;
        }
    }

    if (move[UP] == true)
    {
        this->y -= move_speed - delta_time;
        if (this->y <= next_tile_y)
        {
            this->y = next_tile_y;
            walking = false;
            move[UP] = false;
        }
    }

    if (move[LEFT] == true)
    {
        this->x -= move_speed - delta_time;
        if (this->x <= next_tile_x)
        {
            this->x = next_tile_x;
            walking = false;
            move[LEFT] = false;
        }
    }

    if (move[RIGHT] == true)
    {
        this->x += move_speed + delta_time;
        if (this->x >= next_tile_x)
        {
            this->x = next_tile_x;
            walking = false;
            move[RIGHT] = false;
        }
    }
    colision_mask.setPosition(this->x, this->y);
}

void Player::player_inputs()
{
    if (can_up)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if (walking == false)
            {
                next_tile_y = y - GRID_SIZE;
                move[UP] = true;
                walking = true;
            }
        }
    }

    if (can_down)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {

            if (walking == false)
            {
                next_tile_y = y + GRID_SIZE;
                move[DOWN] = true;
                walking = true;
            }
        }
    }

    if (can_left)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {

            if (walking == false)
            {
                next_tile_x = x - GRID_SIZE;
                move[LEFT] = true;
                walking = true;
            }
        }
    }

    if (can_right)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (walking == false)
            {
                next_tile_x = x + GRID_SIZE;
                move[RIGHT] = true;
                walking = true;
            }
        }
    }
}

void Player::player_col(std::vector<Wall> colisions)
{
    for (auto &i : colisions)
    {
        // Teste Colisão Para cima
        can_up = true;
        can_down = true;
        can_left = true;
        can_right = true;
        if (i.get_colision_mask().getPosition().x == next_tile_x && i.get_colision_mask().getPosition().y == next_tile_y - GRID_SIZE)
        {
            can_up = false;
        }

        // Teste Colisão Para baixo
        if (i.get_colision_mask().getPosition().x == next_tile_x && i.get_colision_mask().getPosition().y == next_tile_y + GRID_SIZE)
        {
            can_down = false;
        }

        // Teste Colisão Para direita
        if (i.get_colision_mask().getPosition().x == next_tile_x + GRID_SIZE && i.get_colision_mask().getPosition().y == next_tile_y)
        {
            can_right = false;
        }

        // Teste Colisão Para esquerda
        if (i.get_colision_mask().getPosition().x == next_tile_x - GRID_SIZE && i.get_colision_mask().getPosition().y == next_tile_y)
        {
            can_left = false;
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