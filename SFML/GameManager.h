#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "EnemyAI.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Update();
	void Render();

	sf::RenderWindow * mpWindow;
	sf::Event mEvent;

private:
	void PollEvents();
	void InitEnemies();
	void InitWindow();

	std::vector<sf::Texture> mEnemyTextures;
	std::vector<EnemyAI> mEnemies;

	sf::Texture mBackgroundTexture;
	sf::Sprite mBackgroundSprite;
};

