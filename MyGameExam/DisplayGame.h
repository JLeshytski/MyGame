#pragma once
#ifndef _DISPLAYGAME_
#define _DISPLAYGAME_
#include "Game.h"


namespace BogdanT
{



//#define GAMESTATE std::vector<std::vector<BogdanT::Card>>
	
	class DisplayGame
	{
	private:
		std::vector<std::vector<BogdanT::Card>> gameState;
		std::vector<std::string> players;
		int trump;
		short x,y;
		Game* gamePtr;

	public:
		DisplayGame(Game* pointerToGame): gamePtr(pointerToGame)
		{
			gameState = gamePtr->GetGameState();
			trump = gamePtr->getTrump();
		}
		~DisplayGame();

	private:

		void setCursor(short _X, short _Y);
		

	public:

		void update();
		void showGameState();

		//Add player name to the list of players
		void addPlayer(std::string playerName);


	};

}
#endif
