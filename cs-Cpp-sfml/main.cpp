//
//  main.cpp
//  cpp-sfml-test
//
//  Created by Dereck de Mezquita on 12/3/21.
//

#include <SFML/Graphics.hpp>

int main() {
    // Create an object of type `RenderWindow`
	// There are multiple constructor types we use `sf::VideoMode()`
    sf::RenderWindow window(sf::VideoMode(512, 512), "Hello world!", sf::Style::Close | sf::Style::Titlebar);

	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			if(evnt.type == evnt.Closed) {
				window.close();
			}
		}
	}

    return 0;
}


