#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "sprite-set/sprite-set.hpp"

TEST_CASE("Testing: spriteset") {
    SpriteSet sprite_test ("resources/sprites/player/player_walking_up.png");
    CHECK(sprite_test.sprites_map.size() == 4);
}

#include "sprite-set/background.hpp"

TEST_CASE("Testing: background") {
    Background bg_test ("resources/sprites/maps/main_room.png", "resources/maps/main_room.csv", sf::Vector2i(0, 0));
    CHECK(bg_test.sprites_map.size() == 425);
}

#include "instances/wall.hpp"

TEST_CASE("Testing: wall") {
    Wall wall_test (0, 0);
    Wall wall_test2 (0, 1);
    CHECK(wall_test.instance_interact() == false);
}

TEST_CASE("Testing: wall") {
    Wall wall_test (0, 0);
    Wall wall_test2 (0, 1);
}

#include "instances/npc.hpp"

TEST_CASE("Testing: npc") {
    Npc npc_test ("jose", 2, 2, "resources/dialogues/blue.txt");
    CHECK(npc_test.get_npc_dialogue());
}

#include "hud/timer.hpp"

TEST_CASE("Testing: timer") {
    Timer tempo (0);
    CHECK(tempo.timer_update() == 0);
}

#include "instances/item.hpp"

TEST_CASE("Testing: item") {
    Item item_test ("choco", 10, 10, 1, "resources/sprites/items/item_choco.png", "resources/sprites/items/item_choco_item.png");
    CHECK(item_test.get_holding() == false);
    CHECK(item_test.get_name() == "choco");
    CHECK(item_test.get_interact_status() == false);
}


#include "animation/animation.hpp"

TEST_CASE("Testing: animation") {
    Npc npc_test ("jose", 2, 2, "resources/dialogues/blue.txt");
    Animation anim_test (&npc_test);
    anim_test.new_state(1, 1, "resources/sprites/npcs/npc-blue/npc_blue_idle_left.png");
    CHECK(anim_test.get_sprite());
}

#include "instances/player.hpp"

TEST_CASE("Testing: player") {
    Player p (4, 4);
    p.player_move(0.3);
    CHECK(p.virtual_position.x == 4);
    CHECK(p.virtual_position.y == 9);
    CHECK(p.next_tile.x == 0);
    CHECK(p.next_tile.y == 0);
}

#include "audio/audio.hpp"  

TEST_CASE("Testing: audio") {
    Audio* som = new Audio();
    som->define_music("resources/audio/ball.wav", 100);
    som->play_sound();
    delete som;
    Audio* music = new Audio();
    music->define_music("resources/audio/ball.wav", 100);
    music->play_music();
    delete music;
}

#include "dialogue/dialogue_tree.hpp"

TEST_CASE("Testing: dialog tree") {
    DialogueTree* arvore = new DialogueTree();
    Node* no = new Node();
    Node* no2 = new Node();
    delete arvore;
    delete no;
    delete no2;
}


#include "game/buttons.hpp"

TEST_CASE("Testing: buttons") {
    sf::Font font;
    font.loadFromFile("resources/fonts/pixel.ttf");
    Button btn (100, 100, 128, 32, &font, "NEW GAME", sf::Color(10, 10, 10, 100), sf::Color(20, 20, 20, 200), sf::Color(40, 40, 40, 144));
    btn.update(sf::Vector2f(30, 30));
}