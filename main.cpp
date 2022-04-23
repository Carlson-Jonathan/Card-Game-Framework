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
#include "cardDeck.h"

int main() {

	srand(time(NULL)); 
	Initializer globalData;

	CardDeck cardDeck(globalData);		

	// Main game loop	
    while(globalData.window.isOpen()) {
		globalData.eventHandler.listen();
		globalData.window.clear(sf::Color(0, 90, 0));

		// ---------- Start coding game here ----------
		globalData.window.draw(cardDeck.deck.front()->cardSprite);



		// -------------------------------------------

		globalData.window.display();
   	}

	return 0;
}

#endif // MAIN_CPP