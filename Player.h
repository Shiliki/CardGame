#pragma once

/* Author: Irene Zaugg, S20672231
* Class: CSC 234-601
* Instructor: Robert Gilanyi
* Due: March 7, 2021

Creates a Player for the game. Each Player has a Hand of cards and a Score, which are represented by objects.
This class also includes several helper functions which can be used to access functions in the Hand and Score classes. */

#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Score.h"

using namespace std;

class Player {
public:
	Player(string, Deck&); // Constructor.

	string getName(); // Returns name.
	Card draw(Deck&);
	void discard(Card, int);
	
	/***Helper classes***/

	int getScore(); // Returns numerical value of score.
	void printHand(); // Calls hand.printHand().
	int updateScore(vector<int>); // Calls updateScore function.

private:
	string name;
	Hand myHand;
	Score myScore;
};