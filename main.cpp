#include <SFML/Graphics.hpp>
#include "Deck.hpp"


int main()
{
	Deck deck;
	deck.printDeck();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Cards");

	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
	window.clear();
	window.display();
}