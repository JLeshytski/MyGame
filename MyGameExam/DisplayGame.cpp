#include "stdafx.h"
#include "DisplayGame.h"

std::vector<std::string> suits{"Hearts","Diamonds","Clubs","Spades"};
std::vector<std::string> ranks{"Six","Seven","Eight","Nine","Ten","Jack","Queen","King","Ace"};



BogdanT::DisplayGame::~DisplayGame()
{

}




void BogdanT::DisplayGame::setCursor(short _X, short _Y)
{
	x = _X;
	y = _Y;
	SetCursorPos(x,y);
}



void BogdanT::DisplayGame::setColor(short foreColor, short bkgndColor)
{
	static HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, bkgndColor << 4 | foreColor);
}




void BogdanT::DisplayGame::addPlayer(std::string playerName)
{
	players.push_back(playerName);
}



int BogdanT::DisplayGame::makeChoice()
{
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
		if (choice < 0) choice = gameState[0].size()-1;
		if (choice > gameState[0].size() - 1) choice = 9;
		if (choice > 10) choice = 0;

		if (13 == key) return key;
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
	for (int i=0;i<players.size();++i)
	{
		setCursor(0,i*25);
		std::cout << players[i] << std::endl;
		for (int j = 0;j<gameState[i].size();++j)
		{
			if (!i && j == choice)
				setColor(0,7);
			setCursor(j+1,i*25);
			std::cout << ranks[gameState[i][j].getRank()] << " " 
				<<suits[gameState[i][j].getSuit()] << std::endl;
			setColor(7, 0);
		}
	}
	setCursor(9, 0);
	if (9 == choice)
		setColor(0, 7);

	std::cout << "End Attack" << std::endl;
	setColor(7,0);

	if (10 == choice)
		setColor(0, 7);

	std::cout << "Draw the pile" << std::endl;
	setColor(7, 0);

	setCursor(9, 25);
	std::cout << "Game field" << std::endl;
	int n = 0;
	for (BogdanT::Card curCard : gameState[0])
	{
		setCursor(10 + n++, 25);
		std::cout << ranks[curCard.getRank()] << " " << suits[curCard.getSuit()] << std::endl;
	}
	std::cout << std::endl;
}
