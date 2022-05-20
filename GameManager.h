#pragma once

/* Author: Irene Zaugg, S20672231
* Class: CSC 234-601
* Instructor: Robert Gilanyi
* Due: March 7, 2021

Runs all functions for the game, which are called from the main method. */

#include "Deck.h"
#include "Player.h"


typedef Player *PlayerPtr;

class GameManager {
public:
	GameManager(int); // Constructor
	void setupPlayers(); // Builds players[] array.
	void playCards(int); // Runs draw/discard phase of game.
	bool chooseGroups(int, vector<int>&); // Manages error checking and updates score during scoring phase of game.
	string scoring(); // Calculates and prints winning score.

	/* Helpers */
	string currentPlayer(int); // Returns name of currently active player.
	void currentHand(int); // Prints hand of currently active player.
	bool deckEmpty(); // Returns true if deck pointer is at last element.

private:
	int numPlayers; // Number of players.
	PlayerPtr* players; // Dynamic array containing Players.
	Deck gameDeck; // Deck of Cards.

	//Scoring
	int* playerScores; // Contains scores which match up with players[] array.
	void printScores(); // Helper function for scoring(). Prints formatted scores.
	void removeDuplicates(vector<int>&); // Helper function for chooseGroups(). Removes duplicate entries from user chosen cards.
};