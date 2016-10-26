#pragma once
#include <SFML\Graphics.hpp>
#include <string>

class FadeAppearance:public sf::Drawable
{
public:
	FadeAppearance(std::string&, sf::Vector2f, sf::Vector2f,double,double);
	~FadeAppearance();

	void play();
	void update();
	bool fadeOver()const;

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	const double m_time_fade;
	const double m_step;
	double m_last_a;
	bool m_can_be_drawed;
	bool m_fade_over;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

