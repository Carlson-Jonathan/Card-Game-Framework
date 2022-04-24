// Copyright Jonathan Carlson 2022

#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>
using namespace std;

#include <time.h>
#include "initializer.h"
#include "cardTable.h"

int main() {

	// Initialze main variables
	srand(time(NULL)); 
	Initializer globalData;
	CardTable   cardTable(globalData);

	// Main game loop	
    while(globalData.window.isOpen()) {
		globalData.eventHandler.listen();
		globalData.window.clear(sf::Color(0, 90, 0));

		// ---------- Start coding game here ----------

		// Demo text:
		globalData.window.draw(cardTable.text);

		// Draws entire deck on screen in 2 rows just for demo.
		cardTable.drawCardsOnTable();

		// -------------------------------------------

		globalData.window.display();
   	}

	return 0;
}

#endif // MAIN_CPP