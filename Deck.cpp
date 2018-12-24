#include "Deck.hpp"
#include <iostream>

Deck::Deck()
{
	//Make a standard deck
	//13 faces x 4 suits
	m_numFaces = 13;
	m_numSuits = 4;
	//init card count to 52
	m_cardCount = 52;
	CardSuit suit = CardSuit::CLUBS;
	for (int i = 0; i < 4; i++) {
		switch (i) {
		case 0: suit = CardSuit::CLUBS;
			break;
		case 1: suit = CardSuit::DIAMONDS;
			break;
		case 2: suit = CardSuit::HEARTS;
			break;
		case 3: suit = CardSuit::SPADES;
			break;
		}
		for (int j = 1; j <= 13; j++) {
			Card newCard(static_cast<CardFace>(j), suit);
			deck.push_back(newCard);
		}
	}

}

//Shuffle deck.
void Deck::shuffle()
{
	std::random_shuffle(deck.begin(), deck.end());
}

//Shuffle deck multiple times
void Deck::shuffle(unsigned int numShuffles)
{
	for (unsigned int i = 0; i < numShuffles; i++) {
		std::random_shuffle(deck.begin(), deck.end());
	}
}

// Adds top (back) card to hand vector passed
// in as reference. Returns false if no cards.
bool Deck::drawTop(std::vector<Card> &hand)
{
	if (deck.size() > 0) {
		Card top = deck.back();
		//delete back 
		deck.pop_back();
		//decrement card count
		m_cardCount--;
		//add top card to hand
		hand.push_back(top);
		return true;
	}
	//deck is empty
	return false;
}

//Print the face and suit values for each card.
void Deck::printDeck()
{
	for (unsigned int i = 0; i < deck.size(); i++) {
		std::cout << "Card " << i + 1 << ":\n";
		std::cout << "Face: " << static_cast<int>(deck[i].getCardFace()) << std::endl;
		std::cout << "Suit: " << static_cast<int>(deck[i].getCardSuit()) << std::endl;
	}
}

// Overloaded subscript operator [] to return the card at a
// specific index of the deck vector
Card & Deck::operator[](const int index)
{
	return deck[index];
}

// Get number of cards in deck
int Deck::getCardCount()
{
	return m_cardCount;
}
