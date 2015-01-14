#include "splashscreen.h"

void SplashScreen::Show(sf::RenderWindow& window)
{
	sf::Texture image;
	image.loadFromFile("img/SplashScreen.jpg");
	sf::Sprite Sprite(image);

	window.draw(Sprite);
	window.display();

	sf::Event event;
	while(true)
	{
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::KeyPressed
				|| event.type == sf::Event::MouseButtonPressed
				|| event.type == sf::Event::Closed )
			{
				return;
			}
		}
	}
}