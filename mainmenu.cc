#include "mainmenu.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
	//Setup clickable regions

	//Play button coordinates
	MenuItem playButton;
	playButton.rect.left = 312;
	playButton.rect.top = 284;
	playButton.rect.width = 400;
	playButton.rect.height = 100;
	playButton.action = Play;

	//Exit button coordinates
	MenuItem exitButton;
	exitButton.rect.left = 312;
	exitButton.rect.top = 400;
	exitButton.rect.width = 400;
	exitButton.rect.height = 100;
	exitButton.action = Exit;

	//Add menu buttons to list
	menuItems_.push_back(playButton);
	menuItems_.push_back(exitButton);

	//Load the menu image from file
	char currentImage = 'R';

	std::list<MenuItem>::iterator it;

	for(it = menuItems_.begin(); it != menuItems_.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;

		//If the coordinate where click occurred is on this menu item, return it's action
		if(menuItemRect.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
		{
			if((*it).action == Play)
			{
				currentImage = 'P';
			}
			else if((*it).action == Exit)
			{
				currentImage = 'E';
			}
		}
	}

	sf::Texture image;
	switch(currentImage)
	{
		case 'R':
			image.loadFromFile("img/mainmenuREG.jpg");
			break;
		case 'P':
			image.loadFromFile("img/mainmenuPLAY.jpg");
			break;
		case 'E':
			image.loadFromFile("img/mainmenuEXIT.jpg");
			break;
	}
	sf::Sprite Sprite(image);

	window.draw(Sprite);
	window.display();

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for(it = menuItems_.begin(); it != menuItems_.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;

		//If the coordinate where click occurred is on this menu item, return it's action
		if(menuItemRect.contains(x, y)) return (*it).action;
	}
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event event;

	while(true)
	{
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				return Exit;
			}
			else
			{
				return HandleClick(event.mouseButton.x, event.mouseButton.y);
			}
		}
	}
}







