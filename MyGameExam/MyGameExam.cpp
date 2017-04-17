// MyGameExam.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
//#include "DisplayGame.h"

class DisplayGame;

int main()
{
	srand(time(NULL));
	BogdanT::DisplayGame* game = new BogdanT::DisplayGame();
	game->mainMenu();
	


    return 0;
}
