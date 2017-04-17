#pragma once
#ifndef _GAME_
#define _GAME_

#include "HumanPlayer.h"
#include "Card.h"
#include "Deck.h"
#include "ComputerPlayer.h"



namespace BogdanT
{
	enum GameCondition {InProcess,Win,Draw};
	class DisplayGame;

	class Game
	{

	private:

		DisplayGame* dGamePtr;
		Deck deck;
		std::vector<Card> dPile;
		std::vector<Player*> players;


	private:

		void registerPlayer(Player* playerPtr);
		void dealTheCards();
		void _printGameCondition();

	public:
		Game(DisplayGame *pointeToDGame, int numOfHumanPlayers, int numOfComputerPlayers);
		~Game();

	public:


		int startTheGame();

		
		int makeChoice();
		int getTrump();
		std::vector<std::vector<Card>> GetGameState();
	};

}

#endif