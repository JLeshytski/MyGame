#include "stdafx.h"
#include "DiscardPile.h"


BogdanT::DiscardPile::DiscardPile()
{
}


BogdanT::DiscardPile::~DiscardPile()
{
}

void BogdanT::DiscardPile::add(const Card & recievedCard)
{
	dPile.push_back(recievedCard);
}

BogdanT::Card BogdanT::DiscardPile::getCard()
{
	Card ret(dPile.back());
	dPile.pop_back();
	return ret;
}

void BogdanT::DiscardPile::Clear()
{
	dPile.clear();
}

bool BogdanT::DiscardPile::isEmpty()
{
	return dPile.empty();
}

size_t BogdanT::DiscardPile::getSize()
{
	return dPile.size();
}
