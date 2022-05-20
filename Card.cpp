#include <iostream>
#include "Card.h"

using namespace std;

/* Default constructor.*/
Card::Card() {
	rank = -1;
	suit = 'w';
}

/* Constructor. Utilizes setNumber and setColor functions to determine number and color of card.
Input param:
	rank: number 1-52 from card deck array.
Ending state:
	constructed card object containing a number and color based on card rank. */
Card::Card(int number) {
	setRank(number);
	setSuit(number);
}

// Prints color and number, i.e. "6r".
void Card::printCard() {
	if (suit == 'w')
		cout << 'w';
	else
		cout << rank << suit;
}

/* Returns true if Card has been set to empty (suit = NULL, rank = 99). */
bool Card::isEmpty() {
	if (rank == 99 || suit == NULL)
		return true;
	else
		return false;
}

/* Returns rank. */
int Card::getRank() {
	return rank;
}

/* Returns suit. */
char Card::getSuit() {
	return suit;
}

/* Sets value for number based on rank / 5 (or -1 to represent wild card).
* Starting param:
*	rank: number 1-52 from deck array.
* Ending paray:
*	number set to either rank / 5 if rank is 50 or less. Set to -1 (wild card) if 50 or 51. */
void Card::setRank(int number) {
	if (number == 99)
		rank = 99; // "empty" card
	else if (number >= 50)
		rank = -1; // -1 = wild card
	else
		rank = (number % 10) + 1;
}

/* Sets value for color based on rank % 5 (or 'w' for wild card).
Starting param:
	rank: number 1-52 from deck array.
Ending param:
	color set to  'r', 'b', 'g', or 'p' based on value of rank % 5, or 'w' if rank is 50 or 51. */
void Card::setSuit(int number) {
	if (number == 99)
		suit = NULL; // "empty" card
	else if (number >= 50)
		suit = 'w'; // wild card
	else {
		switch (number / 10) {
		case 0:
			suit = 'r'; // Red
			break;
		case 1:
			suit = 'b'; // Blue
			break;
		case 2:
			suit = 'g'; // Green
			break;
		case 3:
			suit = 'p'; // Purple
			break;
		case 4:
			suit = 'o'; // Orange
			break;
		}
	}
}

