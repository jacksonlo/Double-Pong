#include "game.h"
#include "splashscreen.h"
#include "mainmenu.h"

void Game::Start()
{
	// If Game is not yet initialized state, then continue, else exit
	if(gameState_ != Uninitialized) { return; }

	mainWindow_.create(sf::VideoMode(1024, 768, 32), "PONG!");
	player1_.Load("img/paddle.png");
	player1_.SetPosition((1024/2)-45,700);

	gameState_ = Game::ShowingSplash;

	while(!isExiting())
	{
		gameLoop();
	}

	mainWindow_.close();
}

bool Game::isExiting()
{
	if(gameState_ == Game::Exiting) return true;
	else return false;
}

void Game::gameLoop()
{
	sf::Event event;
	while(mainWindow_.pollEvent(event))
	{
		switch(gameState_)
		{
			case Game::ShowingMenu:
				ShowMenu();
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					gameState_ = Game::ShowingSplash;
					ShowSplashScreen();
				}
				break;

			case Game::ShowingSplash:
				ShowSplashScreen();
				break;

			case Game::Playing:
				mainWindow_.clear(sf::Color::Black);
				player1_.Draw(mainWindow_);
				mainWindow_.display();
				if(event.type == sf::Event::Closed)
				{
					gameState_ = Game::Exiting;
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					gameState_ = Game::ShowingMenu;
					ShowMenu();
				}
				break;
		}
	}
}

void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(mainWindow_);
	gameState_ = Game::ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(mainWindow_);

	switch(result)
	{
		case MainMenu::Exit:
			gameState_ = Game::Exiting;
			break;

		case MainMenu::Play:
			gameState_ = Game::Playing;
			break;
	}
}

Game::GameState Game::gameState_ = Uninitialized;
sf::RenderWindow Game::mainWindow_;
PlayerPaddle Game::player1_;
