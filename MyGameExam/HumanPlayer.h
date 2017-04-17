#pragma once
#ifndef _HUMANPLAYER_
#define _HUMANPLAYER_
#include "Player.h"
#include "Hand.h"

namespace BogdanT
{
	class Game;

	class HumanPlayer: public Player
	{
	private:
		std::string name;
		std::unique_ptr<Hand> handPtr;
		std::vector<Card>*  dPilePtr;
		Game* gamePtr;

	public:
		HumanPlayer(Hand* pointerToHand, std::vector<Card>* pointerToDPile, std::string playerName, Game* _gamePtr)
			: Player(), handPtr(pointerToHand), dPilePtr(pointerToDPile), name(playerName), gamePtr(_gamePtr){}
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
