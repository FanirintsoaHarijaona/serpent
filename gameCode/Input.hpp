#ifndef INPUT_HPP
#define INPUT_HPP

#include <SFML/Graphics.hpp>
#include "Serpent.hpp"
class Input{

//constructeur pour gérer les inputs aux claviers
    public:
        Input();
        void manageInput(sf::RenderWindow &window,Serpent &snake);
        sf::Event getEvent() const;
        void setButton(int bouton,bool etat);
        bool getButtonUp() const;
        bool getButtonDown() const;
        bool getButtonRight() const;
        bool getButtonLeft() const;

    private:
        sf::Event event;
        bool up,down,right,left;
        enum{UP,DOWN,RIGHT,LEFT};
};
#endif