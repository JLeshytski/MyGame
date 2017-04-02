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

void BogdanT::DisplayGame::addPlayer(std::string playerName)
{
	players.push_back(playerName);
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
		int n = 1;
		for (BogdanT::Card curCard : gameState[i])
		{
			setCursor(n++,i*25);
			std::cout << ranks[curCard.getRank()] << " " << suits[curCard.getSuit()] << std::endl;
		}
		std::cout << std::endl;
	}


	std::cout << "Game field" << std::endl;
	for (BogdanT::Card curCard : gameState[0])
	{
		std::cout << ranks[curCard.getRank()] << " " << suits[curCard.getSuit()] << std::endl;
	}
	std::cout << std::endl;
}
