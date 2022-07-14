#include <iostream>
#include <SFML/Graphics.hpp>
#include "Input.hpp"
#include <iostream>
#include "World.hpp"
using namespace std;

int main(){
    sf::RenderWindow window(sf::VideoMode(640,480),"Game2D");
    window.setFramerateLimit(5);
    window.setVerticalSyncEnabled(true);
    Serpent snake;
    Apple apple;
    Input input;
    World world(window);
//Boucle principale du jeu
    while(window.isOpen()){
       input.manageInput(window,snake);
       snake.move();
       snake.extend(apple,window);
       if(snake.extend(apple,window))
            apple.setPosition(window);
       world.checkCollision(snake,window);
       window.clear();
       world.draw(window);
       snake.draw(window);
       apple.draw(window);
       window.display();

    }
    return 0;
}