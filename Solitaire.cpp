#include "Solitaire.hpp"
#include <string>
#include <iostream>
#include <Windows.h>

Solitaire::~Solitaire()
{
	for (int i = 0; i < texVec.size(); i++) {
		delete texVec[i];
	}
}


//Assign the textures to the sprites based on an existing deck
void Solitaire::createCardSprites(Deck deckIn)
{
	//create the sprite vector
	for (int i = 0; i < deckIn.getCardCount(); i++) {
		std::string face, suit;
		if (deckIn[i].getCardFace() == CardFace::ACE) {
			face = "ace";
		}
		else if (deckIn[i].getCardFace() == CardFace::TWO) {
			face = "2";
		}
		else if (deckIn[i].getCardFace() == CardFace::THREE) {
			face = "3";
		}
		else if (deckIn[i].getCardFace() == CardFace::FOUR) {
			face = "4";
		}
		else if (deckIn[i].getCardFace() == CardFace::FIVE) {
			face = "5";
		}
		else if (deckIn[i].getCardFace() == CardFace::SIX) {
			face = "6";
		}
		else if (deckIn[i].getCardFace() == CardFace::SEVEN) {
			face = "7";
		}
		else if (deckIn[i].getCardFace() == CardFace::EIGHT) {
			face = "8";
		}
		else if (deckIn[i].getCardFace() == CardFace::NINE) {
			face = "9";
		}
		else if (deckIn[i].getCardFace() == CardFace::TEN) {
			face = "10";
		}
		else if (deckIn[i].getCardFace() == CardFace::JACK) {
			face = "jack";
		}
		else if (deckIn[i].getCardFace() == CardFace::QUEEN) {
			face = "queen";
		}
		else if (deckIn[i].getCardFace() == CardFace::KING) {
			face = "king";
		}
		if (deckIn[i].getCardSuit() == CardSuit::CLUBS) {
			suit = "clubs";
		}
		else if (deckIn[i].getCardSuit() == CardSuit::DIAMONDS) {
			suit = "diamonds";
		}
		else if (deckIn[i].getCardSuit() == CardSuit::HEARTS) {
			suit = "hearts";
		}
		else if (deckIn[i].getCardSuit() == CardSuit::SPADES) {
			suit = "spades";
		}

		//make texture name
		std::string textureName;
		textureName = face + "_of_" + suit + ".png";
		//OutputDebugString(textureName);
		//add link to texture folder
		std::string imgFolder;
		imgFolder = "img/Playing Cards/PNG-cards-1.3/";
		//get the texture link
		std::string linkToTex;
		linkToTex = imgFolder + textureName;
		//create texture object
		sf::Texture *newTex = new sf::Texture;
		if (!newTex->loadFromFile(linkToTex)) {
			std::cout << "Error loading file " << linkToTex << std::endl;
		}
		texVec.push_back(newTex);
		//create sprite object
		sf::Sprite newSprite(*newTex);
		//scale sprite to 1/10 size (will be 50 x 72.6)
		newSprite.scale(0.1f, 0.1f);
		//push to sprite vector
		cardSpriteVec.push_back(newSprite);
	}

}

void Solitaire::displayCards(sf::RenderWindow &window)
{
	for (int i = 0; i < cardSpriteVec.size(); i++) {
		window.draw(cardSpriteVec[i]);
	}
}

void Solitaire::addSpriteToHand(std::vector<sf::Sprite> &handIn)
{
	handIn.push_back(cardSpriteVec.back());
}

void Solitaire::setCardGrid(float xIn, float yIn)
{
	int counter = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			cardSpriteVec[counter].setPosition((xIn + 5) * i + xIn, 0.5 * yIn * j + yIn);
			counter++;
		}
	}
}

void Solitaire::grabCard(float mouseXPos, float mouseYPos)
{
	//WIP
}

void Solitaire::grabCard(sf::Vector2f mousePos)
{
	for (int i = 0; i < cardSpriteVec.size(); i++) {
		if (cardSpriteVec[i].getGlobalBounds().contains(mousePos)) {
			//cardSpriteVec[i].setOrigin(mousePos);
			cardSpriteVec[i].setPosition(mousePos);
		}
	}
}
