#include "ClassAppearance.h"
#include <iostream>

using namespace std;
ClassAppearance::ClassAppearance() :m_started(false), m_sum(0)
{
	m_anim.loadFromFile("data/spritesheet/final.png");
	m_main_anim.setSpriteSheet(m_anim);
	for (int i = 0; i < 10; ++i)
		m_main_anim.addFrame(sf::IntRect(i * 234, 0, 234, 160));

	m_animated_sprite = AnimatedSprite(sf::seconds(TIME_ANIM), true, false);
	m_animated_sprite.setPosition(sf::Vector2f(310, 250));
}


ClassAppearance::~ClassAppearance()
{
}

void ClassAppearance::start()
{
	m_started = true;

}

void ClassAppearance::update()
{
	sf::Time tmp = m_clock.restart();
	m_sum++;
	if (m_sum < TIME_ANIM *(TIME_ANIM * 100 * MAX_FPS))
	{
		m_animated_sprite.play(m_main_anim);

		m_animated_sprite.update(tmp);
	}
	else {
		m_animated_sprite.stop();
		m_started = false;
	}

}

void ClassAppearance::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (m_started)
		target.draw(m_animated_sprite);
}
