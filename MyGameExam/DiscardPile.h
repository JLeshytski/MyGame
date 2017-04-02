#pragma once
#ifndef _DISCARDPILE_
#define _DISCARDPILE_

#include "Card.h"

namespace BogdanT
{


	class DiscardPile
	{
	private:
		std::vector<Card> dPile;
	public:
		DiscardPile();
		~DiscardPile();

	public:

		void add(const Card& recievedCard);
		Card getCard();
		void Clear();
		bool isEmpty();
		size_t getSize();

	};


}
#endif
