#ifndef CARDDECK_H
#define CARDDECK_H

#include <iostream>
using namespace std;

#include <memory>
#include <queue>
#include "card.h"
#include "miscellaneous.h"

class CardDeck {
public:

    CardDeck(Initializer & globalData) {
        this->globalData = &globalData;
        this->cardNames = Miscellaneous::getAllFileNamesFromDirectory("Images/Objects/PlayingCards/100x150");
        shuffleDeck(this->cardNames);
        generateCardDeck();
    }

    // I am probably going to regret making this a queue instead of a vector.
	queue<shared_ptr<Card>> deck;

    //----------------------------------------------------------------------------------------------

    // Need functions to divide deck by 2, 3 and 4.
    pair<queue<shared_ptr<Card>> , queue<shared_ptr<Card>>> splitDeck() {
        pair<queue<shared_ptr<Card>>, queue<shared_ptr<Card>>> decks;


        return decks;
    }

    //----------------------------------------------------------------------------------------------

    void shuffleDeck(vector<string> cardNames) {
        short deckSize = cardNames.size();
        while(deckSize) {
            short index = Miscellaneous::generateRandomNumber(deckSize--) - 1;
            cout << "Random index: " << index << endl;
            cardNames.push_back(cardNames[index]);
            cardNames.erase(cardNames.begin() + index);

        }
        this->cardNames = cardNames;
    }

    //----------------------------------------------------------------------------------------------

private:
    vector<string> cardNames;
    Initializer* globalData;

    //----------------------------------------------------------------------------------------------

    void generateCardDeck() {
        for(string & i : this->cardNames) {
            i = globalData->textures.getTextureName(i);
        }

        for(string i : this->cardNames) {
            deck.push(shared_ptr<Card>(new Card(*globalData, i)));
        }
    }

};

#endif // CARDDECK_H