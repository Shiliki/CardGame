#include <array>
#include "Deck.h"
#include "Card.h"
#include <time.h>
#include <iostream>

using namespace std;
/* Constructor.
precondition:
	deck[] array empty, pointers null.
postcondition:
	deck[] array filled with Card objects and shuffled.
	topCard points to beginning of deck, lastCard points to end of deck.*/
Deck::Deck() {
	for (int i = 0; i < 52; i++)
		deck[i] = Card(i);
	shuffle();

	topCard = deck;
	lastCard = deck + 52;

}

/* Shuffles deck.
precondition:
	deck[] is a sorted collection of 52 Cards.
postcondition:
	Cards in deck[] are randomly shuffled.*/
void Deck::shuffle() {
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 52; i++) {
		int random = rand() % 52;
		Card temp = deck[i];
		deck[i] = deck[random];
		deck[random] = temp;
	}
}

/* Draws a card from the top of the deck.
precondition:
	*topCard points to first available element in deck[]
postcondition:
	returns card *topCard was pointing to and advances pointer */
Card Deck::drawCard() {
	topCard++;
	return *(topCard - 1);
}

/* Determines if last card has been drawn (end of play phase of game)
precondition:
	topDeck points to any element in deck[] or to lastCard + 1.
postcondition:
	returns false if topDeck points to element in deck[].
	returns true if topDeck points to lastCard + 1. */
bool Deck::isEmpty() {
	if (topCard >= lastCard)
		return true;
	else
		return false;
}