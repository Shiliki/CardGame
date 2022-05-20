#pragma once

/* Author: Irene Zaugg, S20672231
* Class: CSC 234-601
* Instructor: Robert Gilanyi
* Due: March 7, 2021

Creates an array of 52 Cards, using a basic for-loop count to instantiate each Card.
Uses a pointer to keep track of "top card" in deck (next available element) and to
determine when the draw/discard phase of the game has ended.

*TODO* This Class could be made reusable by using a dynamic array and taking a number
of ranks and suits as constructor parameters (i.e. Deck(10, suits[4], 6) creates a Deck of 46 cards
with 4 suits, numbered 1-10, and 6 "wild" cards.) Adaptations to calculations in the Card class
would allow any type of deck to be created. */

#include "Card.h"

class Deck {
public:
	Deck(); // Constructor
	void shuffle(); // Shuffles deck.
	Card drawCard(); // Returns "top card" on deck using pointer, then advances pointer.
	bool isEmpty(); // Returns true if pointer is at last element of deck.

private:
	int numCards;
	Card deck[52];
	Card* topCard; // Points to next available element in deck.
	Card* lastCard; // Points to last element in deck.
};