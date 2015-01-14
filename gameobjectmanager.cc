#include "gameobjectmanager.h"

GameObjectManager::GameObjectManager()
{

}

GameObjectManager::~GameObjectManager()
{
	std::for_each(gameObjects_.begin(), gameObjects_.end(),GameObjectDeallocator());
}

void GameObjectManager::Add(std::string name, VisibleGameObject* gameObject)
{
	gameObjects_.insert(std::pair<std::string, VisibleGameObject*>(name, gameObject));
}

void gameObjectManager::Remove(std::string name)
{
	std::map<std::string, VisibleGameObject*>::iterator results = gameObjects_.find(name);
	if(results != gameObjects.end())
	{
		delete results->second;
		gameObjects_.erase(results);
	}
}

VisibleGameObject* GameObjectManager::Get(std::string name) const
{
	std::map<std::string, VisibleGameObject*>::const_iterator results = gameObject_.find(name);
	if(results == gameObjects_.end())
	{
		return 0;
	}
	return results->second;
}

int GameObjectManager::GetObjectCount() const
{
	return gameObjects_.size();
}

void GameObjectManager::DrawAll(sf::RenderWindow& renderWindow)
{
	std::map<std::string, VisibleGameObject*>::const_iterator itr = gameObjects_.begin();
	while(itr != gameObjects_.end())
	{
		itr->second->Draw(renderWindow);
		itr++;
	}
}




