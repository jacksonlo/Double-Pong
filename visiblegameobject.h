#ifndef _VISIBLEGAMEOBJECT_H_
#define _VISIBLEGAMEOBJECT_H_
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class VisibleGameObject
{
public:
	VisibleGameObject();
	virtual ~VisibleGameObject();

	virtual void Load(std::string filename);
	virtual void Draw(sf::RenderWindow& window);
	virtual void SetPosition(float x, float y);

private:	
	sf::Sprite sprite_;
	sf::Texture image_;
	std::string filename_;
	bool isLoaded_;
};

#endif