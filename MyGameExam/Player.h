#pragma once
#ifndef _PLAYER_
#define _PLAYER_

#include "Card.h"


namespace BogdanT
{

	class Player
	{
	public:

		Player();
		virtual~Player();

	public:

		virtual std::vector<Card> GetCardsInHand() = 0;
		virtual void Print() = 0;

		virtual void drawDeck() = 0;
		virtual void drawDPile() = 0;
		virtual Card atack() = 0;
		virtual Card defend() = 0;
		virtual bool isDone() = 0;
		virtual bool isThrowInAble() = 0;
		virtual bool isDefendAble() = 0;

	};
}

#endif
