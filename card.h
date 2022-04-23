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
		cardSprite.setOrigin(-100, -100);	

        setCardValue(cardName);
        setCardSuite(cardName);
        printCardInfo(cardName);
    }

    //----------------------------------------------------------------------------------------------

    short value = 0;
    string suite = "unset";
 	sf::Sprite cardSprite; 

    //----------------------------------------------------------------------------------------------

    void printCardInfo(string cardName) {
        cout << "[]" << endl;
        cout << cardName << endl;
        cout << "   Value: " << this->value << endl;
        cout << "   Suite: " << this->suite << endl;
    }

    //----------------------------------------------------------------------------------------------

private:
    Initializer* globalData;
    map<char, short> faceCardValues = {{'j', 11}, {'q', 12}, {'k', 13}, {'a', 14}};

    //----------------------------------------------------------------------------------------------

    void setCardValue(string cardName) {
        if(isdigit(cardName[0])) {
            if(cardName[0] == 49)
                this->value = 10;
            else
                this->value = cardName[0] - 48;
        }
        else
            this->value = faceCardValues[cardName[0]];
    }

    //----------------------------------------------------------------------------------------------

    void setCardSuite(string cardName) {
        size_t found = cardName.find("f_");
        if (found != string::npos)
            this->suite = cardName.substr(found + 2);
    }
};

#endif // CARD_H