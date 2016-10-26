#pragma once

#include <vector>
#include "Core.h"
#include "YesNoBox.h"
#include "ClassAppearance.h"
#include "FadeAppearance.h"

class Game
{
public:
	Game();
	~Game();
	void run();


private:
	sf::RenderWindow mWindow;
	Core* m_core;
	Package* m_data;
	STATES m_state;
	ClassAppearance m_app;
	FadeAppearance m_fade;
private:
	const sf::Time TimePerFrame;

private:
	void processEvent();
	void update(sf::Time);
	void render();

};
double distanceEuclidienne(sf::Vector2f, sf::Vector2f);


