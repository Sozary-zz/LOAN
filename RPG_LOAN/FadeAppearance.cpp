#include "FadeAppearance.h"

using namespace std;

FadeAppearance::FadeAppearance(string& s, sf::Vector2f pos, sf::Vector2f size, double time_fade, double fps) :m_time_fade(time_fade), m_step(255.f / (fps*m_time_fade)), m_last_a(0), m_can_be_drawed(false), m_fade_over(false)
{
	if (!m_texture.loadFromFile(s)) return;
	m_sprite.setTexture(m_texture);

	m_sprite.setPosition(pos);
	m_sprite.setScale(sf::Vector2f(size.x / m_texture.getSize().x, size.y / m_texture.getSize().y));

}


FadeAppearance::~FadeAppearance()
{
}

void FadeAppearance::play()
{
	m_can_be_drawed = true;
}

void FadeAppearance::update()
{
	if (m_can_be_drawed && !m_fade_over)
	{
		double tmp = m_last_a + m_step;
		if (tmp < 255) {
			m_last_a = tmp;
			m_sprite.setColor(sf::Color(255, 255, 255, round(m_last_a)));
		}
		else {
			m_fade_over = true;
		}
	}

}

bool FadeAppearance::fadeOver() const
{
	return m_fade_over;
}

void FadeAppearance::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (m_can_be_drawed)
		target.draw(m_sprite);
	
}
