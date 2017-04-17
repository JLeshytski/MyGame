#pragma once
#ifndef _COMPUTERPLAYER_
#define _COMPUTERPLAYER_

#include "Player.h"
#include "Hand.h"
#include "Card.h"

namespace BogdanT
{
	class ComputerPlayer : public Player
	{
	private:
		std::string name;
		std::unique_ptr<Hand> handPtr;
		std::vector<Card>* dPilePtr;

	public:
		ComputerPlayer(Hand* pointerToHand, std::vector<Card>* pointerToDPile, std::string playerName) 
			: handPtr(pointerToHand), dPilePtr(pointerToDPile), name(playerName) {}
		~ComputerPlayer();


	public:
		Card atack();
		Card defend();
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