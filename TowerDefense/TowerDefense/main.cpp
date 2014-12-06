#include "Map.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

int main()
{
	int direction = 0;
	float gridspacing = 20;
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("mario.png")) // different picture than was used in Peter's code
		return EXIT_FAILURE;

	texture.setSmooth(true);

	sf::Sprite sprite(texture);
	// Load a music to play
	// Start the game loop

	sprite.setPosition(90, 90);
	sprite.setScale(sf::Vector2f(0.01f, 0.01f)); // resized mario to fit within a reasonably sized grid

	/*sf::Text text;
	sf::Font font;
	if (!font.loadFromFile("Paragon.ttf"))
	{
	// error...
	}

	text.setFont(font);
	text.setString("Thing left: ");
	text.setPosition(10,10);*/

	// Grid set up
	sf::VertexArray verlines (sf::Lines, 80); // verlines is an array of size 80 that contains start and end vertices for 40 vertical lines
	for (int i = 0; i < 80; i++)
	{
		verlines [i].position = sf::Vector2f ((gridspacing * i), 0); // gridspacing can be changed by changing the declaration, but in order to 
		i++;														// maintain the ratio with the window, must be a factor of both 800 and 600
		verlines [i].position = sf::Vector2f ((gridspacing * (i - 1)), 600);
	}
	sf::VertexArray horlines (sf::Lines, 60); // horlines is an array of size 60 that contains start and end vertices for 30 horizontal lines
	for (int i = 0; i < 60; i++)
	{
		horlines [i].position = sf::Vector2f (0, (gridspacing * i));
		i++;
		horlines [i].position = sf::Vector2f (800, (gridspacing * (i - 1)));
	}


	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window : exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		/*sf::Vertex line[] =
		{
			sf::Vertex(sf::Vector2f(grid, 0)),
			sf::Vertex(sf::Vector2f(grid, 600))
		};*/
		switch (direction)
		{
			// Implicit: case 0: does nothing (stand still)
		case 1:
			// left key is pressed: move our character
			sprite.move(-0.1, 0);
			break;
		case 2:
			// left key is pressed: move our character
			sprite.move(0.1, 0);
			break;
		case 3:
			// left key is pressed: move our character
			sprite.move(0, -0.1);
			break;
		case 4:
			// left key is pressed: move our character
			sprite.move(0, 0.1);
			break;
		}
		/*sf::Vector2i mousePos(0,0);

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
		mousePos =  sf::Mouse::getPosition();
		text.setString("Thing left: " + std::to_string(sf::Mouse::getPosition().x - window.getPosition().x) + "\nX left " + std::to_string(sprite.getPosition().x));
		}

		if(sprite.getGlobalBounds().contains(mousePos.x - window.getPosition().x, mousePos.y - window.getPosition().y)){
		sprite.rotate(0.75);
		}*/

		//sprite.move(sf::Vector2f(5, 10));
		//sprite.rotate(0.01);
		// Clear screen
		window.clear();
		// Draw the sprite
		window.draw(sprite);
		//window.draw(text);
		window.draw(verlines);
		window.draw(horlines);
		// Draw the string
		window.display();
	}
	return EXIT_SUCCESS;
}