#include <SFML/Graphics.hpp>
#include "Solitaire.hpp"
#include "Deck.hpp"


int main()
{

	Deck deck;
	Solitaire game;
	std::vector<sf::Sprite> spriteVec = game.createCardSprites(deck);

	//set Position of sprites
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 4; j++) {
			spriteVec[i].setPosition(50.f * i + 50.f, 72.6f * j + 40.f);
		}
	}

	sf::RenderWindow window(sf::VideoMode(800, 600), "Cards");

	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
		}


		window.clear();
		for (int i = 0; i < spriteVec.size(); i++) {
			window.draw(spriteVec[i]);
		}
		window.display();


	}

}