#include "stdafx.h"
#include "Hand.h"



std::vector<BogdanT::Card>::iterator BogdanT::Hand::getMinCardItr()
{
	std::vector<Card>::iterator iter = hand.end();
	int min = 10;
	for (auto i = hand.begin();i!=hand.end();++i)
	{
		if (i->getSuit() != trump && i->getRank() < min)
		{
			min = i->getRank();
			iter = i;
		}
	}
	return iter;
}



std::vector<BogdanT::Card>::iterator BogdanT::Hand::getMinTrumpItr()
{
	std::vector<Card>::iterator iter = hand.end();
	int min = 10;
	for (auto i = hand.begin(); i != hand.end(); ++i)
	{
		if (i->getSuit() == trump && i->getRank() < min)
		{
			min = i->getRank();
			iter = i;
		}
	}
	return iter;
}






std::vector<BogdanT::Card>::iterator BogdanT::Hand::getSameRankCardItr(int _rank)
{
	return std::find_if(hand.begin(), hand.end(), [_rank](const Card& cur) {
		return cur.getRank() == _rank;
	});
}





std::vector<BogdanT::Card>::iterator BogdanT::Hand::getHigherCardItr(const Card & received_card)
{
	auto iter = std::find_if(hand.begin(), hand.end(), [received_card](const Card& card) {
		return card.sameSuit(received_card.getSuit()) && received_card < card;
	});
	return iter;
}





void BogdanT::Hand::Sort()
{
	std::sort(hand.begin(), hand.end(), [](const Card& card1, const Card& card2) {
		return card1.getSuit() < card2.getSuit();
	});

	std::stable_sort(hand.begin(), hand.end(), [](const Card& card1, const Card& card2) {
		return (card1.getSuit() == card2.getSuit() && card1.getRank() < card2.getRank());
	});
}



BogdanT::Hand::~Hand()
{
}





bool BogdanT::Hand::isEmpty()
{
	return hand.empty();
}



void BogdanT::Hand::setTrump(int _trump)
{
	trump = _trump;
}




void BogdanT::Hand::drawn()
{
	while (!(deckp->isEmpty()) && hand.size()<size)
	{
		hand.push_back(deckp->getCard());
	}
	Sort();
}




bool BogdanT::Hand::is_beatable(const Card & received_card)
{
	if (getHigherCardItr(received_card) == hand.end())
	{
		if (received_card.getSuit() != trump)
		{
			return getMinTrumpItr() != hand.end();
		}
		return false;
	}
	return true;
}




BogdanT::Card BogdanT::Hand::getMinCard()
{
	std::vector<Card>::iterator iter = getMinCardItr();
	if(iter == hand.end())
		iter = getMinTrumpItr();
	Card ret(*iter);
	hand.erase(iter);
	return ret;
}



BogdanT::Card BogdanT::Hand::getMinTrump()
{
	auto tmp = getMinTrumpItr();
	Card ret(*tmp);
	hand.erase(tmp);
	return ret;
}




void BogdanT::Hand::Print() const
{
	for (const Card& card : hand)
	{
		std::cout << card.getRank() << " " << card.getSuit() << std::endl;
	}
}




void BogdanT::Hand::Add(Card card)
{
	hand.push_back(card);
}




bool BogdanT::Hand::isSameRankCardPresent(const Card & received_card)
{
	return getSameRankCardItr(received_card.getRank()) != hand.end();
}




BogdanT::Card BogdanT::Hand::getSameRankCard(const Card & received_card)
{
	auto iter = getSameRankCardItr(received_card.getRank());
	Card tmp = *iter;
	hand.erase(iter);
	return  tmp;
}



BogdanT::Card BogdanT::Hand::getCard(const int index)
{
	Card tmp(hand.operator[](index));
	hand.erase(std::find(hand.begin(),hand.end(),hand[index]));
	return tmp;
}

BogdanT::Card BogdanT::Hand::getHigherCard(const Card receivedCard)
{
	auto tmpItr = getHigherCardItr(receivedCard);
	if (tmpItr == hand.end())
	{
		return getMinTrump();
	}
	Card ret(*tmpItr);
	hand.erase(tmpItr);
	return ret;
}

std::vector<BogdanT::Card> BogdanT::Hand::getCards()
{
	return hand;
}


