#pragma once
#ifndef _HUMANPLAYER_
#define _HUMANPLAYER_
#include "Player.h"
#include "DiscardPile.h"
#include "Hand.h"

namespace BogdanT
{

	// создать указатель на отбой и реализовать методы зайти, отбиться, забрать карты, 
	// потянуть карты.

	class HumanPlayer: public Player
	{
	private:
		std::string name;
		std::unique_ptr<Hand> handPtr;
		std::vector<Card>*  dPilePtr;

	public:
		HumanPlayer(Hand* pointerToHand, std::vector<Card>* pointerToDPile, std::string playerName)
			: Player(), handPtr(pointerToHand), dPilePtr(pointerToDPile), name(playerName){}
		~HumanPlayer();

	public:

		Card atack();
		Card defend();

		//is there any cards in the hand
		bool isDone();
		bool isDefendAble();
		bool isThrowInAble();
		void drawDPile();
		void drawDeck();
		std::vector<Card> GetCardsInHand();

		void Print();
	};


}
#endif
