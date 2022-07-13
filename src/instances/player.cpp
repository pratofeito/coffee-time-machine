#include "instances/player.hpp"

Player::Player(int x, int y) : Instance(x, y)
{
    player_state = NOTHING;

    // Inicializa a player_collision colocando ela no vetor de colisões
    player_colision = new Collision(this);

    // animações do personagem
    player_animation = new Animation(this);

    player_animation->new_state(MOVING, UP, "resources/sprites/player/player_walking_up.png");
    player_animation->new_state(MOVING, DOWN, "resources/sprites/player/player_walking_down.png");
    player_animation->new_state(MOVING, LEFT, "resources/sprites/player/player_walking_left.png");
    player_animation->new_state(MOVING, RIGHT, "resources/sprites/player/player_walking_right.png");
    player_animation->new_state(NOTHING, UP, "resources/sprites/player/player_idle_up.png");
    player_animation->new_state(NOTHING, DOWN, "resources/sprites/player/player_idle_down.png");
    player_animation->new_state(NOTHING, LEFT, "resources/sprites/player/player_idle_left.png");
    player_animation->new_state(NOTHING, RIGHT, "resources/sprites/player/player_idle_right.png");

    player_sprite = player_animation->get_sprite();

    // change default player position
    this->virtual_position = sf::Vector2i(4, 9);
    this->projected_position = sf::Vector2f(virtual_position.x * TILE_SIZE, virtual_position.y * TILE_SIZE);
}

Player::~Player()
{
    delete player_colision;
}

void Player::player_move(const float delta_time)
{
    // Verificação redundante, é possível otimizar e parar de verificar todo frame (Resolver nas férias)
    if (player_colision->get_collision(next_tile) == nullptr)
    {
        elapsed_time += delta_time;
        int partial_move = (elapsed_time * GRID_SIZE) / move_time;

        if (partial_move >= GRID_SIZE)
        {
            player_state = MOVING;
            elapsed_time = 0;
            virtual_position.x = next_tile.x;
            virtual_position.y = next_tile.y;
            projected_position = sf::Vector2f(virtual_position.x * GRID_SIZE, virtual_position.y * GRID_SIZE);
        }
        else
        {
            projected_position = sf::Vector2f((virtual_position.x * GRID_SIZE) + (partial_move * move_dir.x),
                                              (virtual_position.y * GRID_SIZE) + (partial_move * move_dir.y));
        }
    }
    else
    {
        player_state = NOTHING;
    }
}

void Player::player_interact()
{
    Instance *object_collidable = player_colision->get_collision(next_tile);

    if (object_collidable != nullptr)
    {

        if (object_collidable->instance_interact() == false)
        {
            player_state = NOTHING;
            x = false;
            z = false;
        }

        if (object_collidable->instanceof <Item>(object_collidable))
        {
            object_collidable->instance_interact(this->bag);
            player_state = MOVING;
        }
    }
    else
    {
        player_state = NOTHING;
    }
}

void Player::check_inputs()
{
    // Move Keys
    arrow_up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    arrow_down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    arrow_left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    arrow_right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

bool Player::uptade_event_player(sf::Event event)
{
    z = false;
    x = false;

    if (event.key.code == sf::Keyboard::Z)
    {
        interact_key = true;
        z = true;
        return true;
    }
    else if (event.key.code == sf::Keyboard::X)
    {
        interact_key = true;
        x = true;
        return true;
    }
    else
    {
        interact_key = false;
        return false;
    }
}

void Player::keyboard_step()
{
    y_direction = arrow_down - arrow_up;
    x_direction = arrow_right - arrow_left;
    elapsed_time = 0;

    // Aviso: Remover a estranheza daqui (Férias)
    if (arrow_up)
    {
        player_state = MOVING;
        looking = UP;
        next_tile.x = virtual_position.x;
        next_tile.y = virtual_position.y + y_direction;
        move_dir = sf::Vector2i(0, y_direction);
    }
    else if (arrow_down)
    {
        player_state = MOVING;
        looking = DOWN;
        next_tile.x = virtual_position.x;
        next_tile.y = virtual_position.y + y_direction;
        move_dir = sf::Vector2i(0, y_direction);
    }
    else if (arrow_left)
    {
        player_state = MOVING;
        looking = LEFT;
        next_tile.x = virtual_position.x + x_direction;
        next_tile.y = virtual_position.y;
        move_dir = sf::Vector2i(x_direction, 0);
    }
    else if (arrow_right)
    {
        player_state = MOVING;
        looking = RIGHT;
        next_tile.x = virtual_position.x + x_direction;
        next_tile.y = virtual_position.y;
        move_dir = sf::Vector2i(x_direction, 0);
    }
    else if (interact_key)
    {
        switch (looking)
        {
        case UP:
            next_tile.x = virtual_position.x;
            next_tile.y = virtual_position.y - 1;
            break;
        case DOWN:
            next_tile.x = virtual_position.x;
            next_tile.y = virtual_position.y + 1;
            break;
        case LEFT:
            next_tile.x = virtual_position.x - 1;
            next_tile.y = virtual_position.y;
            break;
        case RIGHT:
            next_tile.x = virtual_position.x + 1;
            next_tile.y = virtual_position.y;
            break;
        }
        // std::cout << "x: " << next_tile.x << " y: " << next_tile.y << std::endl;
        player_state = INTERACTING;
    }
    else
    {
        player_state = NOTHING;
    }
}

bool Player::instance_interact()
{
    return 0;
}

void Player::instance_draw(sf::RenderTarget *target)
{
    // desenha a sprite do player, que já foi atualizada em update() com a classe animação
    target->draw(*this->player_sprite);
}

void Player::instance_update(const float &delta_time)
{
    switch (player_state)
    {
    case INTERACTING:
        // std::cout << "Case Interacting" << std::endl;
        player_interact();
        break;
    case MOVING:
        // std::cout << "Case Moving" << std::endl;
        player_move(delta_time);
        break;
    }

    // tem que estar como verificação no fim porque ele pode estar movimentando, acabar
    // um pedaço do movimento e ainda continuar pressionado. neste caso ele não deve mudar
    // para o estado parado, mas sim continuar em movimento.
    if (player_state == NOTHING)
    {
        // std::cout << "Case Nothing" << std::endl;
        check_inputs();
        keyboard_step();
    }

    player_animation->update(player_state, looking, delta_time);
    player_sprite->setPosition(projected_position);
}