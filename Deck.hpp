#ifndef DECK_HPP
#define DECK_HPP
#include "Card.hpp"
#include <vector>
#include <algorithm>


class Deck
{
private:
	std::vector<Card> deck;
	int m_numFaces;
	int m_numSuits;
	int m_cardCount;
	
protected:
public:
	Deck();
	void shuffle();
	void shuffle(unsigned int);
	bool drawTop(std::vector<Card> &hand);
	void printDeck();
	Card& operator[] (const int index);
	int getCardCount();
};

#endif //DECK_HPP