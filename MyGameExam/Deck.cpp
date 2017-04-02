#include "stdafx.h"
#include "Deck.h"


BogdanT::Deck::~Deck()
{
}



int BogdanT::Deck::getTrump() const
{
	return trump;
}



bool BogdanT::Deck::isEmpty()
{
	return deck.empty();
}



bool BogdanT::Deck::isFull()
{
	return deck.size() == size;
}




void BogdanT::Deck::Add(Card card)
{
	deck.push_back(card);
}



BogdanT::Card BogdanT::Deck::getCard()
{
	Card tmp = deck.back();
	deck.pop_back();
	return tmp;
}



void BogdanT::Deck::Shuffle()
{
	std::random_shuffle(deck.begin(),deck.end());
}
