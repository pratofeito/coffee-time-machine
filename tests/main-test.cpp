#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "sprite-set/sprite-set.hpp"

TEST_CASE("Testing: SpriteSet - Carregado quantidade correta de sprites") {
    SpriteSet sprite_test ("resources/sprites/player/player_walking_up.png");
    CHECK(sprite_test.sprites_map.size() == 4);
}
