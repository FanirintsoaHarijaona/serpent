#include "Input.hpp"
#include <iostream>
using namespace sf;

Input::Input(){
    up=0;
    down=0;
    right=0;
    left=0;
}
 bool Input::getButtonDown() const{
    return down;
 }
 bool Input::getButtonLeft() const{return left;}
 bool Input::getButtonRight() const{return right;}
 bool Input::getButtonUp() const{return up;}


void Input::manageInput(RenderWindow &window,Serpent &snake ){
    while(window.pollEvent(event)){
        switch(event.type){
            case Event::Closed :
                window.close();
                break;
            case Event::KeyPressed:
                switch(event.key.code){
                    case Keyboard::Escape:
                        window.close();
                        break;
                    case Keyboard::Right:
                        right=true;
                        snake.moveRight();
                        break;
                    case Keyboard::Left:
                        left=true;
                        snake.moveLeft();
                        break;
                    case Keyboard::Up:
                        up=true;
                        snake.moveUp();
                        break;
                    case Keyboard::Down:
                        snake.moveDown();
                        down=true;
                        break;
                }
            case Event::KeyReleased:
                switch(event.key.code){
                    case Keyboard::Right:
                        right=false;
                        break;
                    case Keyboard::Left:
                        right=false;
                        break;
                    case Keyboard::Up:
                        up=false;
                        break;
                    case Keyboard::Down:
                        down=false;
                        break;
                    default :
                    break;
                }
            default:
            break;
        }
    }
}

Event Input::getEvent() const{
    return event;
}
void Input::setButton(int bouton,bool etat ){
        switch(bouton){
            case UP:
                up=etat;
                break;
            case DOWN:
                down=etat;
                break;
            case LEFT:
                left=etat;
                break;
            case RIGHT:
                right=etat;
                break;
            default:
                break;
        }
}