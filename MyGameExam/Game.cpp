#include "stdafx.h"
#include "Game.h"





BogdanT::Game::Game(int numOfHumanPlayers, int numOfComputerPlayers)
{
	dGamePtr = std::make_unique<DisplayGame>(this);
	for (int i = 0; i < numOfHumanPlayers; ++i)
	{
		std::stringstream name;
		name << "Player" << i + 1;
		registerPlayer(new HumanPlayer(new Hand(&deck),&dPile,name.str(),this));
		dGamePtr->addPlayer(name.str());
	}
	for (int i = 0; i < numOfComputerPlayers; ++i)
	{
		std::stringstream str;
		str << "Computer" << i+1;
		registerPlayer(new ComputerPlayer(new Hand(&deck),&dPile,str.str()));
		dGamePtr->addPlayer(str.str());
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



int BogdanT::Game::startTheGame()
{
	GameCondition gameCondition = InProcess;
	Player* p1 = players[0];
	Player* p2 = players[1];
	Card tmpCard(0,0);

	while (gameCondition == InProcess)
	{
		if (p1->isDone())
		{
			gameCondition = (p2->isDone() ? Draw : Win);
			break;
		}

		bool defence;
		while (dPile.empty() || p1->isThrowInAble())
		{
			dGamePtr->update();
			tmpCard = p1->atack();

			if (tmpCard.getRank() < 0)
			{
				break;
			}

			dPile.push_back(tmpCard);
			dGamePtr->update();

			if (p2->isDefendAble())
			{
				tmpCard = p2->defend();

				if (tmpCard.getRank() < 0)
				{
					defence = false;
					break;
				}

				dPile.push_back(tmpCard);
				defence = true;
				dGamePtr->update();
			}
			else
			{
				defence = false;
				break;
			}
		}

		if (defence)
		{
			std::swap(p1, p2);
		}

		else
		{
			p2->drawDPile();
			system("cls");
			std::cout << "Player draw the discard pile" << std::endl;
			_getch();
			dGamePtr->update();
		}

		if (!(dPile.empty()))
			dPile.clear();
		dealTheCards();

		
	}

	switch (gameCondition)
	{
	case GameCondition::Win:
		return (std::find(players.begin(),players.end(),p1)-players.begin());

	case GameCondition::Draw:
		return -1;
	}

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




std::vector<std::vector<BogdanT::Card>> BogdanT::Game::GetGameState()
{
	std::vector<std::vector<BogdanT::Card>> ret;
	for (Player* curPlayer : players)
	{
		ret.push_back(curPlayer->GetCardsInHand());
	}
	ret.push_back(dPile);
	return ret;
}
