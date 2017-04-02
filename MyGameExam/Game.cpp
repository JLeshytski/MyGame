#include "stdafx.h"
#include "Game.h"





BogdanT::Game::Game(int numOfHumanPlayers, int numOfComputerPlayers)
{
	dGamePtr = std::make_unique<DisplayGame>(this);
	//dGamePtr = new DisplayGame(this);
	for (int i = 0; i < numOfHumanPlayers; ++i)
	{
		std::string name;
		std::cout << "Input name of Player" << i + 1 << ":";
		registerPlayer(new HumanPlayer(new Hand(&deck),&dPile,name,this));
		dGamePtr->addPlayer(name);
	}
	for (int i = 0; i < numOfComputerPlayers; ++i)
	{
		std::stringstream str;
		str << "Computer" << i;
		registerPlayer(new ComputerPlayer(new Hand(&deck),&dPile,str.str()));
	}
	
	dealTheCards();
}


BogdanT::Game::~Game()
{

}



void BogdanT::Game::registerPlayer(Player * playerPtr)
{
	players.push_back(playerPtr);
}



void BogdanT::Game::dealTheCards()
{
	for (int i = 0; i < players.size(); ++i)
	{
		players[i]->drawDeck();
	}
}



BogdanT::GameCondition BogdanT::Game::startTheGame()
{
	GameCondition gameCondition = InProcess;
	Player* p1 = players[0];
	Player* p2 = players[1];
	while (gameCondition == InProcess)
	{
		if (players[0]->isDone())
		{
			gameCondition = (players[1]->isDone() ? Draw : Win);
			break;
		}

		bool defence;
		while (dPile.empty() || players[0]->isThrowInAble())
		{
			dPile.push_back(players[0]->atack());
			printGameCondition();

			if (players[1]->isDefendAble())
			{
				dPile.push_back(players[1]->defend());
				defence = true;
				printGameCondition();
			}
			else
			{
				players[1]->drawDPile();
				defence = false;
				std::cout << "Player draw the discard pile" << std::endl;
				_getch();
				printGameCondition();
				break;
			}
		}

		if (!(dPile.empty()))
			dPile.clear();
		dealTheCards();

		if (defence)
		{
			std::swap(players[0],players[1]);
		}
	}
	return gameCondition;
}



void BogdanT::Game::printGameCondition()
{
	system("cls");
	for (Player* curPlayer : players)
	{
		curPlayer->Print();
		std::cout << std::endl << std::endl << std::endl;
	}
	std::cout << "Trump " << deck.getTrump() << std::endl  << "Game field" << std::endl << std::endl;
	for(Card& curCard : dPile)
	{
		curCard.Print();
		std::cout << std::endl;
	}
	_getch();
}



int BogdanT::Game::makeChoice()
{
	return dGamePtr->makeChoice();
}



int BogdanT::Game::getTrump()
{
	return deck.getTrump();
}




GAMESTATE BogdanT::Game::GetGameState()
{
	GAMESTATE ret;
	ret.push_back(dPile);
	for (Player* curPlayer : players)
	{
		ret.push_back(curPlayer->GetCardsInHand());
	}
	return ret;
}
