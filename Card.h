#pragma once

/* Author: Irene Zaugg, S20672231
* Class: CSC 234-601
* Instructor: Robert Gilanyi
* Due: March 7, 2021

Constructs a Card object. Ranks are between 1 and 10; suits are b (blue), g (green), o (orange), p (purple), or r red).
Also provides conditions for 'w' (wild) cards and "empty" cards, which represent cards that have been played and
cannot be reused. */

class Card
{
public:
	Card(int rank); // Constructor. Takes value from deck and sets the color and number values.
	Card(); // Default constructor.
	void printCard(); // Prints full value of card as a string (Color + Number, i.e. "o9")
	bool isEmpty(); // Returns true if Card has been set to "empty" values.
	int getRank(); // Returns rank (for purposes of comparing cards in scoring phase).
	char getSuit(); // Returns suit (for purposes of comparing cards in scoring phase).
private:
	void setRank(int); // Sets value for rank variable.
	void setSuit(int); // Sets value for suit variable.

	int rank; // Value of card. From 52-card deck: 50/5. Numbers 50 and 51 are wild.
	char suit; // Color of card. From 52-card deck: 50 % 5 determines color. Numbers 50 and 51 are wild.
};