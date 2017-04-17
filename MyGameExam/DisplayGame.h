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
		//list of players name
		std::vector<std::string> players;
		int trump;
		Game* gamePtr;
		int choice;
		HANDLE hConsole;

	public:
		DisplayGame() : gamePtr(nullptr)
		{
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		}
		~DisplayGame();

	private:

		//Set cursot position
		void setCursor(short _X, short _Y);

		//Set color of the text
		void setColor(short foreColor, short bkgndColor);
		

	public:

		void RegisterGame(Game* pointerToGame);

		void update();
		void showGameState();
		void showGameResult(int playerIndex);

		void mainMenu();

		//Add player name to the list of players
		void addPlayer(std::string playerName);

		int makeChoice();


	};

}
#endif
