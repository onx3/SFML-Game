#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Game
{
public:
	Game();
	~Game();

	void PollEvents();

	void Update();
	void Render();

	sf::RenderWindow * mpWindow;
	sf::Event mEvent;

private:
	void InitWindow();
};

