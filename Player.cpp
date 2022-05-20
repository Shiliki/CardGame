#include <string>
#include <iostream>
#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Score.h"

Player::Player(string name, Deck &myDeck) {
	this->name = name;
	myHand = Hand(myDeck);
	myScore = Score();
}

string Player::getName() {
	return name;
}

Card Player::draw(Deck &myDeck) {
	return myDeck.drawCard();
}

void Player::discard(Card newCard, int discardCard) {
	myHand.addCard(newCard, discardCard);
}

/***Helpers***/

int Player::getScore() {
	return myScore.getScore();
}

void Player::printHand() {
	myHand.printHand();
}

int Player::updateScore(vector<int> userChoices) {
	myScore.updateScore(userChoices, myHand);
	return myScore.getScore();
}