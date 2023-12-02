#include <SFML/Graphics.hpp>

int main() {
	//Create a windows in SFML
	sf::RenderWindow window(sf::VideoMode(800, 600), "Window");

	//Create a circle to represent in the windows
	sf::CircleShape player(30.0f);
	player.setFillColor(sf::Color::Green);
	player.setPosition(100.0f, 100.0f);

	//Initial velocity
	float velocidadX = 100.0f;
	float velocidadY = 50.0f;

	sf::Clock clock;

	//Loop
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		//Update the position
		sf::Time deltaTime = clock.restart();
		float timeSecond = deltaTime.asSeconds();
		float desplazamientoX = velocidadX * timeSecond;
		float desplazamientoY = velocidadY * timeSecond;

		player.move(desplazamientoX, desplazamientoY);

		//Condition of the position;
		sf::Vector2f position = player.getPosition();
		if (position.x < 0 || position.x > window.getSize().x - player.getRadius() * 2) {
			velocidadX = -velocidadX;
		}
		if (position.y < 0 || position.y > window.getSize().y - player.getRadius() * 2) {
			velocidadY = -velocidadY;
		}

		//Clean the window
		window.clear();

		//Draw the player in movement
		window.draw(player);

		//Show the window
		window.display();
	}

	return 0;
}

