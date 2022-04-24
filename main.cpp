// Copyright Jonathan Carlson 2022

#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>
using namespace std;

#include <time.h>
#include <vector>
#include "initializer.h"
#include "miscellaneous.h"
#include "cardDeck.h"

int main() {

	srand(time(NULL)); 
	Initializer globalData;

	CardDeck cardDeck(globalData);		

	for(short i = 0, j = -100, k = -50; i < cardDeck.deck.size(); i++, j -= 40, k -= 10) {
		cardDeck.deck[i].cardSprite.setOrigin(j, k);
		if(i == 25) {
			j = -60;
		}
	}

	sf::Text text;
	sf::Font font; 

	if (!font.loadFromFile("Fonts/Robusta-Regular.ttf")) cout << "Font not found" <<	endl; 
	text.setFont(font); 
	text.setString("SFML Card Game Framework by Jonathan Carlson");
	text.setCharacterSize(48); 
	text.setFillColor(sf::Color::Yellow);
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
	               textRect.top  + textRect.height / 2.0f);
	text.setPosition(sf::Vector2f(globalData.screenWidth / 1.65, 60));	

	short i = 0;
	short j = 0;


	// Main game loop	
    while(globalData.window.isOpen()) {
		globalData.eventHandler.listen();
		globalData.window.clear(sf::Color(0, 90, 0));

		// ---------- Start coding game here ----------
		globalData.window.draw(text);

		// Draws entire deck on screen in 2 rows just for demo.
		for(short i = 0; i < cardDeck.deck.size(); i++) {
			globalData.window.draw(cardDeck.deck[i].cardSprite);
		}

		j = 0;

		// -------------------------------------------

		globalData.window.display();
   	}

	return 0;
}

#endif // MAIN_CPP