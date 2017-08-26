#pragma once
#ifndef _DISPLAYGAME_
#define _DISPLAYGAME_
#include "Game.h"
#include "Display.h"


namespace BogdanT
{
	
	class DisplayGame: public Display
	{
	private:
		
		//contains the list of users cards and discard pile
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
			CONSOLE_CURSOR_INFO lpCursor;
			GetConsoleCursorInfo(hConsole, &lpCursor);
			lpCursor.bVisible = false;
			lpCursor.dwSize = 1;
			SetConsoleCursorInfo(hConsole, &lpCursor);
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
