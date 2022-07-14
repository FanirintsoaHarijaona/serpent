#include "Apple.hpp"

Apple::Apple(){
    apple.setRadius(8.f);
    apple.setPosition(sf::Vector2f(128.f,128.f));
}

void Apple::setPosition(sf::RenderWindow &window){
    sf::Vector2f position;
    position.x=(rand()%20)*16;
    position.y=(rand()%20)*16;
    apple.setPosition(position);
}

void Apple::draw(sf::RenderWindow &window){
    window.draw(apple);
}

sf::Vector2f Apple::getPosition() const{
    return apple.getPosition();
}