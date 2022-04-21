// Copyright Jonathan Carlson 2022

#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>
using namespace std;

#include <time.h>
#include <vector>
#include <memory>
#include "initializer.h"
#include "miscellaneous.h"
#include "card.h"

vector<shared_ptr<Card>> generateCardDeck(Initializer & globalData) {

	vector<string> cardNames = Miscellaneous::getAllFileNamesFromDirectory("Images/Objects/PlayingCards/100x150");

	for(string & i : cardNames) {
		i = globalData.textures.getTextureName(i);
	}

	vector<shared_ptr<Card>> cardDeck;

	for(string i : cardNames) {
		cardDeck.push_back(shared_ptr<Card>(new Card(globalData, i)));
	}


	return cardDeck;
}


int main() {

	srand(time(NULL)); 
	Initializer globalData;

	vector<shared_ptr<Card>> cardDeck = generateCardDeck(globalData);
		

	// Main game loop	
    while(globalData.window.isOpen()) {
		globalData.eventHandler.listen();
		globalData.window.clear(sf::Color(0, 90, 0));

		// ---------- Start coding game here ----------

		// Draw background on a loop.
		// globalData.window.draw(globalData.background);
		globalData.window.draw(cardDeck[2]->cardSprite);



		// -------------------------------------------

		globalData.window.display();
   	}

	return 0;
}

#endif // MAIN_CPP