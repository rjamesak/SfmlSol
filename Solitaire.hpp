#ifndef SOLITAIRE_HPP
#define SOLITAIRE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Deck.hpp"


class Solitaire
{
private:
	std::vector<sf::Sprite> cardSpriteVec;
protected:
public:
	std::vector<sf::Sprite> createCardSprites(Deck deckIn);


};

#endif //SOLITAIRE_HPP