#pragma once
#ifndef _CARD_
#define _CARD_


namespace BogdanT
{

	class Card
	{

		friend std::ostream& operator<<(std::ostream& stream, const Card& card)
		{
			stream << card.getRank() << ";" << card.getSuit();
			return stream;
		}

	private:

		int rank;
		int suit;

	public:
		Card(int _rank, int suit): rank(_rank), suit(suit)
		{
		}

		virtual ~Card();

	public:

		int getRank()const;
		int getSuit()const;
		bool sameSuit(int siut)const;
		bool sameRank(int _rank)const;

		// returns true if received the same card
		bool operator==(const Card& received_card);
		bool operator==(const int rank);
		bool operator!=(const Card& received_card);
		bool operator>(const Card& received_card)const;
		bool operator<(const Card& recived_card)const;

		void Print();

	};


}

#endif

