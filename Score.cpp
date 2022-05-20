#include "Score.h"
#include "Hand.h"
#include <iostream>

Score::Score(){
	score = 10;
}

/* Returns score.*/
int Score::getScore() {
	return score;
}

/* Uses helper functions to update score.
precondition:
	list of cards passed to other functions, which return a numerical value to be subtracted from score.

	param vector<int> userChoices: indexes of user chosen Cards.
	param Hand& myHand: array of Cards.

postcondition:
	Number of successfully grouped cards has been subtracted from score. Returns 0 if cards are not a legitimage group. */
void Score::updateScore(vector<int> userChoices, Hand& myHand) {
	score = score - groupedCards(userChoices, myHand);
}

/* If user-selected cards belong to a legitimate group, returns number of successfully grouped cards.
precondition:
	User selects 3 or more cards from hand[] to form a group. Tests cardsMatch().

	param vector<int> userChoices: indexes of selected Cards.

postcondition:
	if cardsMatch(): set cards at all selected indexes to "empty" and return number of successfully scored cards.
	if !cardsMatch(): do not change hand[], return score of 0. */
int Score::groupedCards(vector<int> userChoices, Hand &myHand) {
	// Check to see if any cards in group have been used before (are empty).
	for (int i = 0; i < userChoices.size(); i++)
		if (myHand.getCard(userChoices[i]).isEmpty()) {
			return 0;
		}

	// Check if suits or ranks all match. If not, return 0.
	if (!cardsMatch(userChoices, myHand)) {
		cout << "Not a valid group." << endl;
		return 0;
	}
	else { // If group is legitimate, overwrite used cards in hand as "empty".
		for (auto i = userChoices.begin(); i != userChoices.end(); i++) {
			Card tempCard(99);
			myHand.addCard(tempCard, *i);
		}

		// Return number of cards in group.
		cout << userChoices.size() << " cards grouped." << endl;
		return userChoices.size();
	}
}

/* Uses helper functions ranksMatch() and suitsMatch() to determine if all cards in a group match.
precondition:
	param vector<int> userChoices: vector containing indexes of user chosen Cards.
	param Hand& hand: pass by reference to hand[] containing Cards.

postcondition:
	returns true if all chosen Cards share either the same rank or suit, else returns false. */
bool Score::cardsMatch(vector<int> userChoices, Hand& myHand) {
	if (ranksMatch(userChoices, myHand) || suitsMatch(userChoices, myHand)) {
		return true;
	}
	else {
		return false;
	}
}

/* Checks if all user selected cards, stored as indexes in vector, share the same rank.
precondition:
	Assume match is true until non-same ranks are found.
	
	param vector<int> userChoices: indexes of cards entered by user.
	param Hand& myHand: pass by reference for hand[] array of Cards

postcondition:
	After stepping through each chosen card, if any one mismatch is found, return false. Else return true.*/
bool Score::ranksMatch(vector<int> userChoices, Hand& myHand) {
	for (auto i = userChoices.begin(); i < userChoices.end(); i++)
		for (auto j = i + 1; j != userChoices.end(); j++)
			if (myHand.getCard(*i).getRank() != myHand.getCard(*j).getRank()) // Card 1 rank != Card 2 rank
				if (myHand.getCard(*i).getRank() != -1 && myHand.getCard(*j).getRank() != -1) // Check that neither card is wild.
					return false;

	return true;
}

/* Checks if all user selected cards, stored as indexes in vector, share the same suit.
precondition:
	Assume match is true until non-same suits are found.

	param vector<int> userChoices: indexes of cards entered by user.
	param Hand& myHand: pass by reference for hand[] array of Cards

postcondition:
	After stepping through each chosen card, if any one mismatch is found, return false. Else return true.*/
bool Score::suitsMatch(vector<int> userChoices, Hand& myHand) {
	for (auto i = userChoices.begin(); i < userChoices.end(); i++)
		for (auto j = i + 1; j != userChoices.end(); j++)
			if (myHand.getCard(*i).getSuit() != myHand.getCard(*j).getSuit()) // Card 1 rank != Card 2 rank
				if (myHand.getCard(*i).getSuit() != 'w' && myHand.getCard(*j).getSuit() != 'w') // Check if either card is wild.
					return false;

	return true;
}