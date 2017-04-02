// MyGameExam.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "Hand.h"
#include "Deck.h"
#include "Card.h"
#include "Game.h"
using namespace BogdanT;

int main()
{
	srand(time(NULL));
	/*Deck deck;
	Hand hand(&deck);
	Card card(hand.getMinCard());
	std::cout << card.getRank() << " " << card.getSuit() << std::endl
		<< "Hand" << std::endl;
	hand.Print();
	std::pair<int, int> tmp;
	std::cin >> tmp.first >> tmp.second;
	while (hand.isSameRankCardPresent(Card(tmp.first,tmp.second)))
	{
		std::cout << hand.getSameRankCard(Card(tmp.first, tmp.second)) << std::endl;
	}
	std::cout << std::endl << "hand" << std::endl << "trump " << deck.getTrump() << std::endl;
	hand.Print();

	std::cin >> tmp.first >> tmp.second;
	std::cout << "This card is " << (hand.is_beatable(Card(tmp.first, tmp.second)) ? " " : "not ")
		<< "beatable" << std::endl;

	std::cout << "Min Trump = " << hand.getMinTrump() << std::endl;
	std::cin >> tmp.first >> tmp.second;
	std::cout << "card to beat = " << hand.getHigherCard(Card(tmp.first,tmp.second));*/

	Game game(0, 2);
	game.startTheGame();

    return 0;
}
