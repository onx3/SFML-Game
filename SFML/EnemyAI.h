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
	EnemyAI(const sf::Texture & texture);
	~EnemyAI();

	void SetTexture(const sf::Texture & texture);

	void SetPosition(const sf::Vector2f & vec);
	void SetPosition(const float x, const float y);

protected:
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

private:
	sf::Texture mTexture;
	sf::Sprite mSprite;
};