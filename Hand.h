#pragma once

/* Author: Irene Zaugg, S20672231
* Class: CSC 234-601
* Instructor: Robert Gilanyi
* Due: March 7, 2021

Creates a hand of cards, represented currently by an array (see notes in Score.h for alternate build).
Drawing and discarding cards is represented by the addCard() function, which will overwrite a Card
at a given index. "Discarding" a card is illusory. */

#include <array>
#include "Card.h"
#include "Deck.h"

using namespace std;

class Hand {
public:
	Hand(); // Default
	Hand(Deck&); // Constructor.
	void addCard(Card, int index); // Adds card to specified index. Overwrites existing Card (doubles as discard action).
	void printHand(); // Prints hand. Calls Card.printCard() and adds additional formatting.
	Card getCard(int); // Returns Card at given index.
	
private:
	Card hand[10]; // Array of cards in hand

	void sort(); // Sorts hand array.
};