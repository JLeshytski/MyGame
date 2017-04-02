#include "stdafx.h"
#include "Card.h"



BogdanT::Card::~Card()
{
}



int BogdanT::Card::getRank() const
{
	return rank;
}



int BogdanT::Card::getSuit() const
{
	return suit;
}



bool BogdanT::Card::operator==(const Card & received_card)
{
	return rank == received_card.getRank() && suit == received_card.getSuit();
}




bool BogdanT::Card::sameSuit(int suit) const
{
	return this->suit == suit;
}




bool BogdanT::Card::sameRank(int _rank) const
{
	return rank == _rank;
}



bool BogdanT::Card::operator>(const Card & received_card) const
{
	return rank > received_card.getRank();
}




bool BogdanT::Card::operator<(const Card & received_card) const
{
	return rank < received_card.getRank();
}

void BogdanT::Card::Print()
{
	std::cout << getRank() << ';' << getSuit();
}
