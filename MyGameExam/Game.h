#pragma once
#ifndef _GAME_
#define _GAME_

#include "HumanPlayer.h"
#include "Card.h"
#include "Deck.h"
#include "ComputerPlayer.h"



namespace BogdanT
{
#define GAMESTATE std::vector<std::vector<BogdanT::Card>>
	enum GameCondition {InProcess,Win,Draw};
	class DisplayGame;

	class Game
	{

	private:

		std::unique_ptr<DisplayGame> dGamePtr;
		Deck deck;
		std::vector<Card> dPile;
		std::vector<Player*> players;


	private:

		void registerPlayer(Player* playerPtr);
		void dealTheCards();

	public:
		Game(int numOfHumanPlayers, int numOfComputerPlayers);
		~Game();

	public:

		GameCondition startTheGame();
		void printGameCondition();
		int makeChoice();
		int getTrump();
		GAMESTATE GetGameState();
	};

}

#endif