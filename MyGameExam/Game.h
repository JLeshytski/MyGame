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
	class Display;


	// A main Game class.
	// Contains a game logic and Players information

	class Game
	{

	private:

		Display* dGamePtr;
		Deck deck;
		std::vector<Card> dPile;
		std::vector<Player*> players;


	private:

		
		void dealTheCards();

		//helping method
		void _printGameCondition();

	public:
		Game(Display *pointeToDGame, int numOfHumanPlayers, int numOfComputerPlayers);
		~Game();

	public:

		// main game method
		int startTheGame();

		//Registration of new player
		void registerPlayer(Player* playerPtr);
		//method called the same method in Display
		int makeChoice();
		//returns a trump
		int getTrump();
		//returns a game state to Display
		std::vector<std::vector<Card>> GetGameState();
	};

}

#endif