#ifndef WORLD_HPP
#define WORLD_HPP
#include <SFML/Graphics.hpp>
#include <vector>
#include "Serpent.hpp"

class World{
    public:
        World(sf::RenderWindow &window);
        void draw(sf::RenderWindow &window);
        void checkCollision(Serpent &serpent,sf::RenderWindow &window);
        void gameOver(Serpent &snake,sf::RenderWindow &window);
    private:
        using Bordure=std::vector<sf::RectangleShape>;
        Bordure haut,bas,gauche,droite;
        Apple apple;
        sf::Font font;
        sf::Text text;
};
#endif