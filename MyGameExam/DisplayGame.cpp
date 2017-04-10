#include "stdafx.h"
#include "DisplayGame.h"

std::vector<std::string> suits{"Hearts","Diamonds","Clubs","Spades"};
std::vector<std::string> ranks{"Six","Seven","Eight","Nine","Ten","Jack","Queen","King","Ace"};



BogdanT::DisplayGame::~DisplayGame()
{

}




void BogdanT::DisplayGame::setCursor(short _X, short _Y)
{
	SetConsoleCursorPosition(hConsole, COORD{ _X,_Y });
}



void BogdanT::DisplayGame::setColor(short foreColor, short bkgndColor)
{
	SetConsoleTextAttribute(hConsole, bkgndColor << 4 | foreColor);
}




void BogdanT::DisplayGame::addPlayer(std::string playerName)
{
	players.push_back(playerName);
}


// Method hilights the cards that player chooses and returns index of chosen card in the hand
int BogdanT::DisplayGame::makeChoice()
{
	choice = 0;
	for (;;)
	{
		system("cls");
		showGameState();
		int key = _getch();
		if (224 == key)
		{
			switch (_getch())
			{
			case 72: --choice;
				break;
			case 80: ++choice;
				break;
			}
		}
		if (choice < 0) choice = 0;
		if (choice > gameState[0].size() - 1 && choice < gameState[0].size()+3) 
			choice = gameState[0].size()+2;
		if (choice > gameState[0].size()+3) choice = 0;

		if (13 == key) return choice;
	}
	return 0;
}




void BogdanT::DisplayGame::update()
{
	gameState = gamePtr->GetGameState();
	showGameState();
}



void BogdanT::DisplayGame::showGameState()
{
	int i = 0; // position X
	for (; i < players.size(); ++i)
	{
		// Printing cards in players hands
		setCursor(i * 25, 0);
		std::cout << players[i] << std::endl;
		for (int j = 0; j < gameState[i].size(); ++j)
		{
			//mark the players choice
			if (!i && j == choice)
				setColor(0, 7);
			setCursor(i * 25, j + 1);
			std::cout << ranks[gameState[i][j].getRank()] << " "
				<< suits[gameState[i][j].getSuit()] << std::endl;
			setColor(7, 0);
		}
	}

	// Printing additional menu points after players hand
	setCursor(0, gameState[0].size()+2);
	if (gameState[0].size()+2 == choice)
		setColor(0, 7);

	std::cout << "End Attack" << std::endl;
	setColor(7,0);

	if (gameState[0].size()+3 == choice)
		setColor(0, 7);

	std::cout << "Draw the pile" << std::endl;
	setColor(7, 0);



	// Printing  discard pile
	setCursor(i*25,0);
	std::cout << "Game field" << std::endl;
	int n = 1;
	for (BogdanT::Card curCard : gameState[2])
	{
		setCursor(i*25,n++);
		std::cout << ranks[curCard.getRank()] << " " << suits[curCard.getSuit()] << std::endl;
	}
	std::cout << std::endl;
}
