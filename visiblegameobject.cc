#include "visiblegameobject.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

VisibleGameObject::VisibleGameObject() : isLoaded_(false) {}

VisibleGameObject::~VisibleGameObject() {}

void VisibleGameObject::Load(std::string filename)
{
	if(!image_.loadFromFile(filename))
	{
		filename_ = "";
		isLoaded_ = false;
	}
	else
	{
		filename_ = filename;
		sprite_.setTexture(image_);
		isLoaded_ = true;
	}
}

void VisibleGameObject::Draw(sf::RenderWindow &renderWindow)
{
  if(isLoaded_)
  {
    renderWindow.draw(sprite_);
  }
}

void VisibleGameObject::SetPosition(float x, float y)
{
  if(isLoaded_)
  {
    sprite_.setPosition(x,y);
  }
}