/* Author: Irene Zaugg, S02672231
Class: CSC 234-601
Instructor: Robert Gilanyi
Due Date: March 7, 2021

Contains main method for game. All functions are handled by the GameManager class. 
Main handles user input. */

#include <iostream>
#include <cstdio>
#include "GameManager.h"

using namespace std;

typedef Player* PlayerPtr;

int main() {
	char playAgain;
	PlayerPtr* players;
	int numPlayers;

	do {
		// Get number of players. Check number is int and between 2 and 4:
		cout << "Enter number of players (2 - 4): " << endl;
		
		// Error checking
		while (!(cin >> numPlayers)) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please enter a number between 2 and 4: " << endl;
		}
		while (numPlayers < 2 || numPlayers > 4) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Number of players must be between 2 and 4: " << endl;
			cin >> numPlayers;
		}

		GameManager game(numPlayers);

		/***Play Cards Phase***/

		int currentPlayer = 0;

		// Draw/discard:
		do {
			game.playCards(currentPlayer);

			// Advance to next player.
			if (currentPlayer < numPlayers - 1)
				currentPlayer++;
			else
				currentPlayer = 0;
		} while (!game.deckEmpty()); // If no more cards in deck, end play phase.

		/***Scoring Phase***/
		printf("\n\n****Choose your Groups*****\n\n");

		vector<int> playerChoices; // Contains entered indexes of cards.
		int* playerScores = new int[numPlayers]; // Array of all players' scores.

		// For each player, enter chosen groups.
		for (int i = 0; i < numPlayers; i++) {
			int input;
			
			printf("%s: Enter numbers for cards in a group. Use -1 to terminate entry.\nEnter 99 to stop entering groups:\n", game.currentPlayer(i).c_str());

			do {
				game.currentHand(i);
				do {
					while (!(cin >> input)) {
						cin.clear();
						cin.ignore(100, '\n');
						cout << "Incorrect input. Try again." << endl;
					}

					while ((input < 0 || input > 9) && (input != -1 && input != 99)) {
						cout << "Cards are numbered 0 - 9. Try again:" << endl;
						cin >> input;
					}
					
					if (input != -1 && input != 99)
						playerChoices.push_back(input);

				} while (input != -1 && input != 99);

				if(playerChoices.size() > 0)
					if (!game.chooseGroups(i, playerChoices)) {
						cout << "Groups must contain at least 3 unique cards. Try again." << endl;
				}
				
				playerChoices.clear();
				cin.clear();
			} while (input != 99);
		}

		/***END GAME***/

		printf("%s is the winner!!\n", game.scoring().c_str());
		cout << "Would you like to play again? (y/n)" << endl;

		cin >> playAgain;
	} while (playAgain == 'y' || playAgain == 'Y');
}