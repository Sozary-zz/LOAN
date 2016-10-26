#pragma once
#include <SFML\Graphics.hpp>
#include "AnimatedSprite.hpp"

#define TIME_ANIM .08f
#define MAX_FPS 60.f

class ClassAppearance :public sf::Drawable
{
public:
	ClassAppearance();
	~ClassAppearance();
	void start();	
	void update();

private:
	sf::Texture m_anim;
	sf::Texture m_class;
	sf::Sprite m_class_sprite;
	Animation m_main_anim;
	AnimatedSprite m_animated_sprite;
	sf::Clock m_clock;
	bool m_started;
	double m_sum;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

