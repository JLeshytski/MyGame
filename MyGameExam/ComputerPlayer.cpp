#include "stdafx.h"
#include "ComputerPlayer.h"



BogdanT::ComputerPlayer::~ComputerPlayer()
{

}




BogdanT::Card BogdanT::ComputerPlayer::atack()
{
	if (dPilePtr->empty())
	{
		return handPtr->getMinCard();
	}
	else
	{
		for (Card curCard : *dPilePtr)
		{
			if (handPtr->isSameRankCardPresent(curCard))
				return handPtr->getSameRankCard(curCard);
		}
	}
}



BogdanT::Card BogdanT::ComputerPlayer::defend()
{
	return handPtr->getHigherCard(dPilePtr->back());
}

bool BogdanT::ComputerPlayer::isDone()
{
	return handPtr->isEmpty();
}



bool BogdanT::ComputerPlayer::isDefendAble()
{
	return handPtr->is_beatable(dPilePtr->back());
}




bool BogdanT::ComputerPlayer::isThrowInAble()
{
	for (Card curCard : *dPilePtr)
	{
		if (handPtr->isSameRankCardPresent(curCard))
			return true;
	}
	return false;
}



void BogdanT::ComputerPlayer::drawDPile()
{
	for (Card& curCard : *dPilePtr)
	{
		handPtr->Add(curCard);
	}
	handPtr->Sort();
	dPilePtr->clear();
}




void BogdanT::ComputerPlayer::drawDeck()
{
	handPtr->drawn();
}

std::vector<BogdanT::Card> BogdanT::ComputerPlayer::GetCardsInHand()
{
	return handPtr->getCards();
}




void BogdanT::ComputerPlayer::Print()
{
	std::cout << name << std::endl;
	handPtr->Print();
}
