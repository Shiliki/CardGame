#include <array>
#include <vector>
#include <iostream>
#include <cstdio>
#include "GameManager.h"
#include "Deck.h"
#include "Player.h"
#include "Score.h"

using namespace std;

/* Constructor.
precondition:
	param int numPlayers: number of players.

postcondition:
	Sets numPlayers and populates the players[] and playerScores[] dynamic arrays.*/
GameManager::GameManager(int numPlayers) {
	this->numPlayers = numPlayers;
	setupPlayers();
	playerScores = new int[numPlayers];
	for (int i = 0; i < numPlayers; i++)
		playerScores[i] = 10;
}

/* Sets up list of players.
precondition:
	players[] dynamic array is not initilialized.

postcondition:
	players[] is populated with Player objects.*/
void GameManager::setupPlayers() {
	string name;
	players = new PlayerPtr[numPlayers];

	for (int i = 0; i < numPlayers; i++) {
		cout << "Player " << i + 1 << ", please enter your name: ";
		cin >> name;
		players[i] = new Player(name, gameDeck);
	}
}

/* Handles the play-cards phase of the game.
precondition:
	All players have Hands of Cards and will take turns drawing from the Deck.
	They may choose to keep or discard a drawn card. If kept, player must choose a Card in their hand to discard. 
	
	param int currentPlayer: index of current player in players[] array.
	
postcondition:
	Player has either replaced a Card in the Hand object or has discarded the card drawn from the Deck (Deck pointer has advanced in both cases). */
void GameManager::playCards(int currentPlayer) {
	printf("%s's turn:\n", players[currentPlayer]->getName().c_str());
	players[currentPlayer]->printHand();
	cout << endl;

	Card newCard = gameDeck.drawCard();
	cout << "You drew ";
	newCard.printCard();
	cout << ". Would you like to keep this card (y/n)?" << endl;
	char input;

	//Check input.
	while (!(cin >> input)) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter y or n: " << endl;
		cin >> input;
	}

	// If player chooses to keep drawn card, choose card to be replaced. Drawn card is not added to hand if player does not choose to keep.
	if (input == 'y' || input == 'Y') { // Keep card
		int discard;
		cout << "Choose a card to discard (0-9): " << endl;

		//Check input:
		while (!(cin >> discard)) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please enter a number 0-9: " << endl;
			cin >> discard;
		}

		while ((discard < 0) || (discard > 9)) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please enter a number 0-9: " << endl;
			cin >> discard;
		}

		// Discard and replace chosen card.
		players[currentPlayer]->discard(newCard, discard);

	} // End keep card
}

/* Checks that a chosen group meets all rules requirements (must be at least 3 cards and cannot contain any previously chosen cards).
precondition:
	param int currentPlayer: index in players[] of currently active player.
	param vector<int> playerChoices: pass by reference vector of player's entered card choices by index in Hand.
	param int previousChoices: pointer to array of previously entered Card indexes in Hand.
	
postcondition:
	If at least 3 unique choices have been entered and all suits match or all ranks match, group is legitimate.
	Number of cards in group are subtracted from score for current player and returns true.
	If either too ma*/
bool GameManager::chooseGroups(int currentPlayer, vector<int>& playerChoices) {
	removeDuplicates(playerChoices); // Trim duplicates out of vector before running other checks.

	if (playerChoices.size() < 3) // Groups must be at least 3 cards.
		return false;
	for (int i = 0; i < playerChoices.size(); i++)
		playerScores[currentPlayer] = players[currentPlayer]->updateScore(playerChoices); // updateScore() reutrns number of successfully grouped cards.
	
	// Group is legitimate and score is updated.
	return true;
}

/* Removes duplicate choices during scoring phase. 

precondition:
	param vector<int>& playerChoices: pass by reference vector containing user-input choices (ints representing indexes of Cards in hand)
	
postcondition:
	If any duplicate indexes were found, they are removed from the vector. */
void GameManager::removeDuplicates(vector<int>& playerChoices) {
	int currentIndex = 0;
	int compare = 1;
	
	while (currentIndex < playerChoices.size() - 1) {
		while(compare < playerChoices.size()){
			if (playerChoices[currentIndex] == playerChoices[compare])
				playerChoices.erase(playerChoices.begin() + compare); // Duplicate found. This will result in size -1, shifting cards left in vector.
			else
				compare++;
		}

		currentIndex++;
		compare = currentIndex + 1;
	}
}

/* Calculates which Player has the lowest score and returns winner's name.
precondition:
	All Players in players[] array have Score objects that are updated with results.
	
postcondition:
	Returns name of Player with lowest score value. */
string GameManager::scoring() {
	int winningScore = playerScores[0];
	string winner = players[0]->getName();

	// Find lowest score.
	for (int i = 0; i < numPlayers; i++) {
		if (playerScores[i] < winningScore) {
			winningScore = playerScores[i];
			winner = players[i]->getName();
		}
	}
	printScores();

	return winner;
}

/* Formatted printing of players' scores.*/
void GameManager::printScores() {
	cout << "Your Scores:" << endl;
	for (int i = 0; i < numPlayers; i++)
		printf("%s:%10d\n", players[i]->getName().c_str(), playerScores[i]);
}

/***Helpers***/
/* Returns name of currently active player as a string. */
string GameManager::currentPlayer(int currentPlayer) {
	return players[currentPlayer]->getName();
}

/* Prints hand of currently active player. */
void GameManager::currentHand(int currentPlayer) {
	players[currentPlayer]->printHand();
}

/* Returns true if pointer in Deck is at last element. */
bool GameManager::deckEmpty() {
	return gameDeck.isEmpty();
}