#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

int main()
{
	// Avoid magic numbers
	const int HANDS = 26;
	bool keepPlaying = true;
	bool warEnd = false;
	string userPlay = "";

	Deck testDeck1;
	testDeck1.createDeck();
	//shuffle for test case 2 and three
	testDeck1.shuffleDeck();

	vector<Card> split1;
	vector<Card> split2;

	for (int i = 0; i < HANDS; i++)
	{
		split1.push_back(testDeck1.deal_a_card());
		split2.push_back(testDeck1.deal_a_card());
	}

	Player player1(split1);
	Player player2(split2);


	vector<Card> buildUp;
	while (player1.getNumCards() > 0 && player2.getNumCards() > 0 && keepPlaying) {

		cout << "Player 1 plays: ";
		Card play1 = player1.play_a_card();
		buildUp.push_back(play1);
		play1.print();

		cout << endl << "Player 2 plays: ";
		Card play2 = player2.play_a_card();
		buildUp.push_back(play2);
		play2.print();

		cout << endl << "----------------------------------------------" << endl;
		cout << endl << "There are  " << player1.getplayedCards() + player2.getplayedCards() << " cards on the pile!" << endl;
		cout << endl << "----------------------------------------------" << endl;

		if (play1.compareTo(play2) == 0) {
			cout << "It is a tie...for this round!" << endl << endl;
			cout << "Each player drops three cards(face down) on the pile, then" << endl;
			cout << "play one more card(face up)" << endl;
			vector<Card> tempBuild1 = player1.dropCards();
			vector<Card> tempBuild2 = player2.dropCards();

			if (player1.getNumCards() == 1 && player2.getNumCards() == 1) {
				cout << "Game is over!" << endl;
				cout << "It is a tie game!" << endl;
				cout << "Player 1 has " << player1.getNumCards() << " cards in hand!" << endl;
				cout << "Player 2 has " << player2.getNumCards() << " cards in hand!" << endl << endl;
				warEnd = true;
				break;
			}
			else if (player1.getNumCards() == 1) {
				cout << "Game is over!" << endl;
				cout << "Player 2 wins the game";
				warEnd = true;
				break;
			}
			else if(player2.getNumCards() == 1){
				cout << "Game is over!" << endl;
				cout << "Player 1 wins the game";
				warEnd = true;
				break;
			}

			for (int i = 0; i < 3; i++) {
				buildUp.push_back(tempBuild1[i]);
			}

			for (int i = 0; i < 3; i++) {
				buildUp.push_back(tempBuild2[i]);
			}

			cout << "----------------------------------------------" << endl;
			cout << endl << "There are  " << player1.getplayedCards() + player2.getplayedCards() << " cards on the pile!" << endl;
			cout << endl << "----------------------------------------------" << endl;
		}else if(play1.compareTo(play2) == 1){
			cout << "Player 1 wins...get all cards from the pile!" << endl;
			player1.addCards(buildUp);
			buildUp.clear();
		}
		else if(play1.compareTo(play2) == -1) {
			cout << "Player 2 wins...get all cards from the pile!" << endl;
			player2.addCards(buildUp);
			buildUp.clear();
		}

		cout << "Player 1 has " << player1.getNumCards() << " cards in hand!" << endl;
		cout << "Player 2 has " << player2.getNumCards() << " cards in hand!" << endl << endl;


		//user input for test case 1 and 2
		cout << "Do you want to continue...for the next round? (N or n to quit)";
		getline(cin, userPlay);

		if (userPlay == "n" || userPlay == "N") {
			cout << "You choose to quit the game!" << endl;
			cout << "Player 1 has " << player1.getNumCards() << " cards in hand!" << endl;
			cout << "Player 2 has " << player2.getNumCards() << " cards in hand!" << endl << endl;
			keepPlaying = false;
		}
		else {
			keepPlaying = true;
		}

	}

	if (warEnd || !keepPlaying) {
		return 0;
	}

	cout << "Game is over!" << endl;
	if (player1.getNumCards() == 0) {
		cout << "Player 2 wins the game";
	}
	else {
		cout << "Player 1 wins the game";
	}

	return 0;
}