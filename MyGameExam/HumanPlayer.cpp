#include "stdafx.h"
#include "HumanPlayer.h"


BogdanT::HumanPlayer::~HumanPlayer()
{

}


BogdanT::Card BogdanT::HumanPlayer::atack()
{
	int cardIndex = gamePtr->makeChoice();
	if (cardIndex < handPtr->getSize())
	{
		return handPtr->getCard(cardIndex);
	}
	return Card(-1, -1);
}



BogdanT::Card BogdanT::HumanPlayer::defend()
{
	int cardIndex = gamePtr->makeChoice();
	if (cardIndex < handPtr->getSize())
	{
		return handPtr->getCard(cardIndex);
	}
	return Card(-1,-1);
}




bool BogdanT::HumanPlayer::isDone()
{
	return handPtr->isEmpty();
}




bool BogdanT::HumanPlayer::isDefendAble()
{
	return handPtr->is_beatable(dPilePtr->back());
}



bool BogdanT::HumanPlayer::isThrowInAble()
{
	for (Card curCard : *dPilePtr)
	{
		if (handPtr->isSameRankCardPresent(curCard))
			return true;
	}
	return false;
}



void BogdanT::HumanPlayer::drawDPile()
{
	for (Card& curCard : *dPilePtr)
	{
		handPtr->Add(curCard);
	}
	handPtr->Sort();
	dPilePtr->clear();
}



void BogdanT::HumanPlayer::drawDeck()
{
	handPtr->drawn();
}



std::vector<BogdanT::Card> BogdanT::HumanPlayer::GetCardsInHand()
{
	return handPtr->getCards();
}



void BogdanT::HumanPlayer::Print()
{
	std::cout << name << std::endl << std::endl;
	handPtr->Print();
}
