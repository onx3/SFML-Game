#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Game
{
public:
	Game();
	~Game();

	void Update();
	void Render();

	sf::RenderWindow * mpWindow;
	sf::Event mEvent;

	sf::RectangleShape mEnemy;

private:
	void PollEvents();
	void InitEnemies();
	void InitWindow();
};

