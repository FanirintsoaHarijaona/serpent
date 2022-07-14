#include "Serpent.hpp"
#include <iostream>
using namespace sf;

Serpent::Serpent(){
    position.x=64;
    position.y=64;
    for(int i=0;i<3;i++){
       serpent.push_back(sf::RectangleShape(sf::Vector2f(16.f,16.f)));
       serpent[i].setPosition(position);
       position.y-=16;
       serpent[i].setFillColor(sf::Color::Green);
    }
    longueur=serpent.size();
    setDirection(Direction::None);
    time=sf::seconds(0.5f);
}



Direction Serpent::getDirection() const {return m_direction;}

void Serpent::setDirection(Direction direction){
    m_direction=direction;
}

bool Serpent::extend(Apple &apple,sf::RenderWindow &window){
    bool extension;
    sf::Vector2f lastPosition=serpent[longueur-2].getPosition();
    if(apple.getPosition()==serpent[0].getPosition()){
        serpent.push_back(sf::RectangleShape(sf::Vector2f(16.f,16.f)));
        serpent[longueur-1].setFillColor(sf::Color::Green);
        serpent[longueur-1].setPosition(lastPosition.x,lastPosition.y+16);
        longueur++;
        extension=true;
    }
    return extension;
}
std::vector<sf::RectangleShape> Serpent::getBody(){
    return serpent;
}
int Serpent::getSizeBody() const{
    return serpent.size();
}
void Serpent::draw(RenderWindow &window){
    for(int i=0;i<longueur;i++)
        window.draw(serpent[i]);
    serpent[0].setFillColor(sf::Color::Yellow);
            
}

void Serpent::moveLeft(){
    m_direction=Direction::Left;
    for(int i=longueur;i>0;i--)
        serpent[i].setPosition(serpent[i-1].getPosition());
    serpent[0].move(sf::Vector2f(-16.f,0));
}

void Serpent::moveRight(){
    m_direction=Direction::Right;
    for(int i=longueur;i>0;i--)
        serpent[i].setPosition(serpent[i-1].getPosition());
    serpent[0].move(sf::Vector2f(16.f,0));
}

void Serpent::moveUp(){
    m_direction=Direction::Up;
    for(int i=longueur;i>0;i--){
        serpent[i].setPosition(serpent[i-1].getPosition());
        }
    serpent[0].move(sf::Vector2f(0,-16.f));
}

void Serpent::moveDown(){
    m_direction=Direction::Down;
    for(int i=longueur;i>0;i--)
        serpent[i].setPosition(serpent[i-1].getPosition());
    serpent[0].move(sf::Vector2f(0,16.f));
}

sf::Time Serpent::getTime(){
    return time;
}

void Serpent::move(){
    while(time<sf::seconds(1.f)){
        if(m_direction==Direction::Left)
            moveLeft();
        else if(m_direction==Direction::Right)
            moveRight();
        else if(m_direction==Direction::Up)
            moveUp();
        else if(m_direction==Direction::Down)
            moveDown();
        time+=sf::seconds(0.9);
    }
    time=sf::seconds(0.9);
}

sf::Vector2f Serpent::getPosition(){
    return serpent[0].getPosition();
}
