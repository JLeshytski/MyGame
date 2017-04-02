#pragma once
#ifndef _HAND_
#define _HAND_


#include "Deck.h"
#include "Player.h"


namespace BogdanT
{

	class Hand
	{
	private:

		size_t size;
		std::vector<Card> hand;
		int trump;

		// pointer to deck
		Deck* deckp;

		//help method


		// returns iterator of min card if it is present and iterator to the end 
		//of vector otherwise
		std::vector<Card>::iterator getMinCardItr();
		// returns iterator of min trump card if it is present in the hand vector
		//and iterator to the end of vector otherwise
		std::vector<Card>::iterator getMinTrumpItr();
		//get iterator of card with the same rank or iterator of the 
		//end of vector if there is no one
		std::vector<Card>::iterator getSameRankCardItr(int _rank);
		//get iterator to the card with higher rank
		std::vector<Card>::iterator getHigherCardItr(const Card& card);

		
		//Define the last card suit in vector as trump
		void setTrump(int _trump);




	public: // constructor and destructor

		Hand(Deck* deck_ptr) : size(6),  deckp(deck_ptr) 
		{ 
			setTrump(deckp->getTrump());
			drawn();
		}
		~Hand();




	public: // class methods

		//Sort card by suit and by rank
		void Sort();

		//Is there any cards in hand
		bool isEmpty();

		//fill hand with cards from Deck(until 6 cards);
		void drawn();

		//check if recieved card can be beaten with cards we have
		bool is_beatable(const Card& received_card);

		//Get min none trump card in case thre is one, or min trump card otherwise
		Card getMinCard();

		//Get min trump card
		Card getMinTrump();

		// Print all cards
		void Print()const;

		//Add received card 
		void Add(Card card);

		// Check if there is card with the same rank present in the hand
		bool isSameRankCardPresent(const Card& received_card);

		//Get card with the same rank from the hand
		Card getSameRankCard(const Card& received_card);

		//Get the card with received index
		Card getCard(const int index);

		//Get the card with higher rank or min trump in case there is no one
		Card getHigherCard(const Card receivedCard);

		//returns the copy of hand Cards
		std::vector<Card> getCards();

	};


}
#endif
