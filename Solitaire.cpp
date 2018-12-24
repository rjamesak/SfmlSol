#include "Solitaire.hpp"
#include <string>
#include <iostream>

//Assign the textures to the sprites based on an existing deck
std::vector<sf::Sprite> Solitaire::createCardSprites(Deck deckIn)
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
		//add link to texture folder
		std::string imgFolder;
		imgFolder = "../img/Playing Cards/PNG-cards-1.3/";
		//get the texture link
		std::string linkToTex;
		linkToTex = imgFolder + textureName;
		//create texture object
		sf::Texture newTex;
		if (!newTex.loadFromFile(linkToTex)) {
			std::cout << "Error loading file " << linkToTex << std::endl;
		}
		//create sprite object
		sf::Sprite newSprite(newTex);
		//scale sprite to 1/10 size (will be 50 x 72.6)
		newSprite.scale(0.1f, 0.1f);
		//push to sprite vector
		cardSpriteVec.push_back(newSprite);
	}

	return cardSpriteVec;
}
