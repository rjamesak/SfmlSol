#ifndef SOLITAIRE_HPP
#define SOLITAIRE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Deck.hpp"


class Solitaire
{
private:
	std::vector<sf::Sprite> cardSpriteVec;
	std::vector<sf::Texture*> texVec;
protected:
public:
	~Solitaire();
	void createCardSprites(Deck deckIn);
	void displayCards(sf::RenderWindow&);
	void addSpriteToHand(std::vector<sf::Sprite> &handIn);
	void setCardGrid(float xIn, float yIn);
	void grabCard(float mouseXPos, float mouseYPos);
	void grabCard(sf::Vector2f mousePos);


};

#endif //SOLITAIRE_HPP