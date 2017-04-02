#pragma once
#ifndef _DECK_
#define _DECK_

#include "Card.h"
#include "Player.h"

namespace BogdanT
{
	class Deck
	{
	private:

		std::vector<Card> deck;
		size_t size;
		int trump;


	public:

		Deck() : size(36) 
		{
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j<9; ++j)
				{
					Add(Card(j, i));
				}
			}
			Shuffle();
			trump = deck.front().getSuit();
		}
		~Deck();
		
		

	public:
		
		int getTrump()const;

		bool isEmpty();
		bool isFull();
		void Add(Card card);
		Card getCard();

		// after testing hide this method to the private!!!!
		void Shuffle();
		
	};

}

#endif
