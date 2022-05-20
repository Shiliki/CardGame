#pragma once

/* Author: Irene Zaugg, S20672231
* Class: CSC 234-601
* Instructor: Robert Gilanyi
* Due: March 7, 2021

Manages scoring for the game. Score starts at 10, and successful groups subtract from the score.

NOTE: As I designed the game originally, I had intended to simply allow players to enter groups of cards,
then subtract the number of successful groupings from 10. As I continued, however, I realized I also needed
a way to restrict players from choosing old cards or choosing the same card multiple times. At least the
problem of re-using cards could easily have been solved by waiting until the end of the game and then
counting the number of cards left in a player's hand; this design could pretty easily be adapted to
this method, even moreso if the players' hands were represented by either dynamic arrays or vectors, rather
than the current method of overwriting cards in the Hand's array with "empty" card values. However, I found
an interesting challenge in getting my original features to work, so I kept with it, just out of curiosity.

(My favorite alternative method: implement vector hand in Hand object, erase "used" cards from vector, then
return hand.size() at end of game.) */

#include "Hand.h"
#include "Card.h"
#include <vector>

class Score {
public:
	Score(); // Constructor
	
	int getScore(); // Returns score.
	void updateScore(vector<int>, Hand&); // Updates score using above helper functions.
	
private:
	int score; // Numerical value of score.

	int groupedCards(vector<int>, Hand&); // Determine if user selected cards are in a legitimate group and return number to subtract from score.
	bool cardsMatch(vector<int>, Hand&); // Returns true if ranksMatch() -or- suitsMatch(), else false.
	bool ranksMatch(vector<int>, Hand&); // Compare ranks of user selected cards.
	bool suitsMatch(vector<int>, Hand&); // Compare suits of user selected cards.
};