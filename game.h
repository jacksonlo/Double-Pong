#ifndef _GAME_H_
#define _GAME_H_
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "playerpaddle.h"
#include "gameobjectmanager.h"

class Game
{
public:
	static void Start();

private:
	static bool isExiting();
	static void gameLoop();

	static void ShowSplashScreen();
	static void ShowMenu();

	enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting };

	static GameState gameState_;
	static sf::RenderWindow mainWindow_; 

	static GameObjectManager gameObjectManager_;
};

#endif