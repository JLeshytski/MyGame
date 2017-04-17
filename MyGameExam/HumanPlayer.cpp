#include "stdafx.h"
#include "HumanPlayer.h"


BogdanT::HumanPlayer::~HumanPlayer()
{

}


BogdanT::Card BogdanT::HumanPlayer::atack()
{
	int cardIndex = -1;
	while (!dPilePtr->size() || cardIndex < 0)
	{
		//cheking if chosen card can be used to atack
		do
		{
			cardIndex = gamePtr->makeChoice();
		} while (dPilePtr->size() && cardIndex < handPtr->getSize() && std::find(dPilePtr->begin(), dPilePtr->end(),
			handPtr->operator[](cardIndex).getRank()) == dPilePtr->end());

		//check if received cardIndex is not bigger than number of cards in hand
		if (cardIndex < handPtr->getSize())
		{
			return handPtr->getCard(cardIndex);
		}
	}

	//in case player decide to end atack
		return Card(-1, -1);
}



BogdanT::Card BogdanT::HumanPlayer::defend()
{
	int cardIndex = -1;
	Card tmpCard(-1, -1);
	do
	{
		cardIndex = gamePtr->makeChoice();
		if (cardIndex > handPtr->getSize()) break;
		else
			tmpCard = handPtr->operator[](cardIndex);
	} while ((tmpCard.getSuit() != dPilePtr->back().getSuit() && tmpCard.getSuit() != gamePtr->getTrump()) 
		|| ((tmpCard.sameSuit(dPilePtr->back().getSuit()) && tmpCard < dPilePtr->back())));

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
