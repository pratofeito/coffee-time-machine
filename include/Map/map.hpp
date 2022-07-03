#ifndef MAP_HPP
#define MAP_HPP

#include <fstream>
#include <sstream>
#include <vector>
#include <SFML/Graphics.hpp>

class Map {

    public:

        std::ifstream input;
        sf::Texture texture;
        std::vector<sf::Sprite> sprites_map;
        std::vector<sf::IntRect> retangulos;
        std::vector<int> valores;
        std::string line;

    public:

        void load_map_assets();
        void draw_map(sf::RenderWindow *window);
        void draw_guide_lines(sf::RenderWindow *window);

};

#endif