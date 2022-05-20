#include "Hand.h"
#include "Deck.h"
#include <array>
#include <iostream>

using namespace std;
/*********Game Play Phase*********/


Hand::Hand() {

}

/* Constructor.
precondition:
	hand[] is empty.
	param Deck &gameDeck: pass by reference for game deck in use.
postcondition:
	hand[] is populated with first 10 elements in gameDeck through use of addCard() function.
	addCard() called using Deck.drawCard() function, which returns next available card
	and advances gameDeck's pointer.*/
Hand::Hand(Deck &gameDeck) {
	for (int i = 0; i < 10; i++)
		addCard(gameDeck.drawCard(), i);
	sort();
}

/* Replaces Card in hand[] at given index with new Card.
precondition:
	hand[] array of 10 Cards, new card is passed in along with user selected card.
	
	param Card newCard: Card object to be placed in hand[].
	param int index: index of selected Card to  be replaced.

postcondition:
	Card at given index has been overwritten with new Card.*/
void Hand::addCard(Card newCard, int index) {
	hand[index] = newCard;
	if (!newCard.isEmpty())
		sort();
}

/* Prints hand to screen in columns so user can select a Card by index number.
precondition:
	hand[] array of 10 cards. During scoring phase, some cards may be "empty" if they have been scored.

postcondition:
	List of "index    Card" has been printed to screen for every unscored card. Utilizes Card.printCard().*/
void Hand::printHand() {
	printf("#%8s\n", "Card");
	cout << "========" << endl;
	for (int i = 0; i < 10; i++) {
		if (!hand[i].isEmpty()) { // Check if Card object has "empty" values.
			printf("%d%5c", i, ' ');
			hand[i].printCard();
			cout << endl;
		}
	}
}

/* Returns Card at given index. */
Card Hand::getCard(int index) {
	return hand[index];
}

/* Sorts hand array.

precondition:
	hand[] array is populated but unsorted, or an unsorted Card has been added.
	
postcondition:
	hand[] array is sorted by suit, then rank.*/
void Hand::sort() {
	int min, bottom, top;
	Card temp;
	
	// Sort by suit:
	for (int i = 0; i < 9; i++) {
		min = i;
		for (int j = i + 1; j < 10; j++)
			if (hand[j].getSuit() < hand[min].getSuit())
				min = j;

		temp = hand[i];
		hand[i] = hand[min];
		hand[min] = temp;
	}

	// Sort by rank
	top = 0;
	bottom = 0;
	
	while (bottom < 10) {
		while (hand[bottom].getSuit() == hand[top].getSuit())
			top++;
	
		for (int i = bottom; i < top; i++) {
			min = i;
			for (int j = i; j < top; j++)
				if (hand[j].getRank() < hand[min].getRank())
					min = j;

			temp = hand[i];
			hand[i] = hand[min];
			hand[min] = temp;
		}

		if (top < 9) {
			bottom = top;
		}
		else break;

	}

	/* For fun: I thought I'd try a wonky bubble sort. Swap this one for above code to see a very colorful set of bugs! */

	// Selection sort by rank.
	/*for (int i = 0; i < 9; i++) {
		min = i;
		for (int j = i + 1; j < 10; j++)
			if (hand[j].getRank() < hand[min].getRank())
				min = j;

		temp = hand[i];
		hand[i] = hand[min];
		hand[min] = temp;
	}

	// Bubble sort until Card's suit matches previous.
	int last = 1;
	int swap = 2;
	int current = 1;
	while (current < 9) {
		if (hand[swap].getSuit() < hand[current].getSuit()) {
			temp = hand[swap];
			hand[swap] = hand[current];
			hand[current] = temp;
			if(current > 1)
				current--;
		}
		else
			current++;
		swap = current + 1;
	}*/
}
