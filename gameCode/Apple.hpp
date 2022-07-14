#ifndef APPLE_HPP
#define APPLE_HPP
#include "SFML/Graphics.hpp"
#include <cstdlib>
#include <iostream>

class Apple{
    public:
        Apple();
        void setPosition(sf::RenderWindow &window);
        void draw(sf::RenderWindow &window);
        sf::Vector2f getPosition() const;
    private:
        sf::CircleShape apple;
};

#endif