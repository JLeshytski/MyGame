#pragma once
#ifndef _DISPLAY_
#define _DISPLAY_

namespace BogdanT
{

	class Display
	{


	public:

		Display(){ }
		virtual ~Display(){ }

	public:
		// A method dedicated to create and connect Game to display
		virtual void RegisterGame(Game* gamePrt) = 0;
		// Updating Game state method
		virtual void update() = 0;
		// A method returns a result of players choice to the Game
		virtual int makeChoice() = 0;
		//Registering new players name in the list of players(called from Game)
		virtual void addPlayer(std::string playerName) = 0;





	};

}
#endif
