#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

#include <SFML/Window.hpp>

#include "initializer.h"

class Card {
public:

    Card() {}
    Card(Initializer & globalData, string cardName) {
        this->globalData = &globalData;

        cardSprite.setTextureRect(sf::IntRect(0, 0, 100, 145));
 	    cardSprite.setTexture(globalData.textures.textures[cardName]);
        cout << "card name: " << cardName << endl;
		cardSprite.setOrigin(-100, -100);	
    }

    short value;
    char suite;
    Initializer* globalData;

	sf::IntRect cardRectangle; 
 	sf::Sprite cardSprite; 

    void setCardValue(string cardName) {

    }

    void setCardSuite(string cardName) {
        
    }

};

#endif // CARD_H