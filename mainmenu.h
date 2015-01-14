#ifndef _MAINMENU_H_
#define _MAINMENU_H_
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <list>

class MainMenu
{
public:
	enum MenuResult { Nothing, Exit, Play };

	struct MenuItem
	{
		sf::Rect<int> rect;
		MenuResult action;
	};

	MenuResult Show(sf::RenderWindow& window);
private:
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(int x, int y);
	std::list<MenuItem> menuItems_;	
	sf::Sprite sprite_;
	sf::Texture image_;
	std::string filename_;
};

#endif