#include <SFML/Graphics.hpp>
#include "Solitaire.hpp"
#include "Deck.hpp"
#include <iostream>


int main()
{

	Deck deck;
	Solitaire game;
	game.createCardSprites(deck);
	std::vector<sf::Sprite> spriteHand;

	sf::Clock gameClock;

	//set Position of sprites
	game.setCardGrid(50.f, 75.f);
	//game.addSpriteToHand(spriteHand);


	sf::RenderWindow window(sf::VideoMode(1200, 800), "Cards");

	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
			
			
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			game.grabCard(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		}

		window.clear();
		game.displayCards(window);
		//window.draw(spriteHand[0]);
		//window.draw(testSprite);
		window.display();



	}

}