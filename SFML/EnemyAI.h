#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

enum class EEnemy
{
	Ship,
	Ufo,
};

//------------------------------------------------------------------------------------------------------------------------

class EnemyAI : public sf::Drawable
{
public:
	EnemyAI();
	EnemyAI(const EEnemy & enemyType);
	~EnemyAI();

	void InitEnemy();

	void SetTexture(const sf::Texture & texture);

	void SetPosition(const sf::Vector2f & vec);
	void SetPosition(const float x, const float y);

protected:
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

private:
	EEnemy mEnemyType;
	sf::Texture mTexture;
	sf::Sprite mSprite;
};