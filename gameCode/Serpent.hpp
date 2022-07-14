#ifndef DEPLACEMENT_HPP
#define DEPLACEMENT_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Apple.hpp"

enum class Direction{None,Up,Down,Right,Left};

class Serpent{
   using SerpentBody=std::vector<sf::RectangleShape>;
     public:
        Serpent();
        //void move(sf::RenderWindow &window,Input &input);
        void draw(sf::RenderWindow &window);
        void setDirection(Direction direction);
        int getSizeBody() const;
        Direction getDirection() const;
        void moveLeft() ;
        void moveRight();
        void moveUp();
        void moveDown();
        void chooseMove();
        void move();
        bool extend(Apple &apple,sf::RenderWindow &window);
        sf::Time getTime();
        sf::Vector2f getPosition();
        std::vector<sf::RectangleShape> getBody();
     private:
         SerpentBody serpent;
         sf::Vector2f position;
         Direction m_direction;
         int longueur;
         sf::Time time;
};

#endif