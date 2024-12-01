#include "player.h"
#include <list>

Player::Player()
{
	numCards = 0;
	cardsPlayed = 0;
}

Player::Player(vector<Card> ini_cards)
{
	numCards = static_cast<int>(ini_cards.size());
	cardsPlayed = 0;
	for (int i = 0; i < ini_cards.size(); i++) {
		cards.push_back(ini_cards[i]);
	}
}

int Player::getNumCards() const
{
	return numCards;
}

int Player::getplayedCards() const
{
	return cardsPlayed;
}



Card Player::play_a_card()
{
	Card temp;
	if (numCards > 0) {
		numCards -= 1;
		temp = cards.front();
		cards.pop_front();
		cardsPlayed++;
	}
	else {
		cout << "No card to play" << endl;
	}
	return temp;

}

void Player::addCards(vector<Card> winningCards)
{
	numCards += static_cast<int>(winningCards.size());
	cardsPlayed -= static_cast<int>(winningCards.size());
	for (int i = 0; i < winningCards.size(); i++) {
		cards.push_back(winningCards[i]);
	}
}

vector<Card> Player::dropCards()
{
	vector<Card> temp;

	if (numCards >= tie) {
		numCards -= tie;
		cardsPlayed += tie;
		list<Card>::iterator it = cards.begin();
		for (int i = 0; i < tie; i++) {
			temp.push_back(*it);
			it = cards.erase(it);
		}
	}
	else {
		numCards = 1;
	}
	return temp;
}

void Player::print() const
{
	for (list<Card>::const_iterator it = cards.begin(); it != cards.end(); it++) {
		it->print();
		cout << "\t";
	}
	cout << endl;
}
