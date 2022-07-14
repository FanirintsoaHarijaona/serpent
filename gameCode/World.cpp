#include "World.hpp"
#include <iostream>

World::World(sf::RenderWindow &window){
    sf::Vector2u taille(window.getSize());
    sf::Vector2f size=(sf::Vector2f)taille;
    for(unsigned int i=0;i<window.getSize().x;i++){
        haut.push_back(sf::RectangleShape(sf::Vector2f(16.f,16.f)));
        haut[i].setPosition(i*16.f,0);
        haut[i].setFillColor(sf::Color::Red);
    }
    for(unsigned int i=0;i<window.getSize().x;i++){
        bas.push_back(sf::RectangleShape(sf::Vector2f(16.f,16.f)));
        bas[i].setPosition(i*16.f,size.y-16.f);
        bas[i].setFillColor(sf::Color::Red);
    }
    for(unsigned int i=0;i<window.getSize().y;i++){
        gauche.push_back(sf::RectangleShape(sf::Vector2f(16,16)));
        gauche[i].setPosition(0,i*16.f);
        gauche[i].setFillColor(sf::Color::Red);
    }
    for(unsigned int i=0;i<window.getSize().y;i++){
        droite.push_back(sf::RectangleShape(sf::Vector2f(16,16)));
        droite[i].setPosition(size.x-16,i*16.f);
        droite[i].setFillColor(sf::Color::Red);
    }
}

void World::draw(sf::RenderWindow &window){
    sf::Vector2u taille=window.getSize();
    for(int i=0;i<taille.x;i++){
        window.draw(haut[i]);
    }
    for(int i=0;i<taille.x;i++){
        window.draw(bas[i]);
    }
    for(int i=0;i<taille.y;i++){
        window.draw(gauche[i]);
    }
    for(int i=0;i<taille.y;i++){
        window.draw(droite[i]);
    }
}

void World::checkCollision(Serpent &snake,sf::RenderWindow &window){
    for(int i=0,j=0;i<window.getSize().x;i++){
        if((snake.getPosition().x==bas[i].getPosition().x && snake.getPosition().y==bas[i].getPosition().y))
            gameOver(snake,window);
    }
    for(int i=0,j=0;i<window.getSize().x;i++){
        if((snake.getPosition().x==haut[i].getPosition().x && snake.getPosition().y==haut[i].getPosition().y))
            gameOver(snake,window);
    }
    for(int i=0,j=0;i<window.getSize().y;i++){
        if((snake.getPosition().x==gauche[i].getPosition().x && snake.getPosition().y==gauche[i].getPosition().y))
            gameOver(snake,window);
    }
    for(int i=0,j=0;i<window.getSize().y;i++){
        if((snake.getPosition().x==droite[i].getPosition().x && snake.getPosition().y==droite[i].getPosition().y))
            gameOver(snake,window);
    }
    int longueurSerpent=snake.getSizeBody();
    for (int i=1;i<longueurSerpent;i++){
        if(snake.getBody()[i].getPosition()==snake.getPosition()){
            gameOver(snake,window);
        }
    }
}

void World::gameOver(Serpent &snake,sf::RenderWindow &window){
    snake.setDirection(Direction::None);
    if (!font.loadFromFile("../polices/the_amazing_spider_man/The Amazing Spider-Man.ttf"))
        std::cout<<"Error loading fonts";
    else {
        text.setFont(font);
        text.setString("GAME OVER\nPRESS DIRECTION KEY TO CONTINUE");
        text.setFillColor(sf::Color::Red);
        text.setCharacterSize(32);
        text.setPosition(sf::Vector2f(128.f,128.f));
        window.clear(sf::Color::Black);
        window.draw(text);
        window.display();
    }
}