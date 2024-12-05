#include "EnemyAI.h"

EnemyAI::EnemyAI()
	: mTexture()
	, mSprite()
{

}

//------------------------------------------------------------------------------------------------------------------------

EnemyAI::EnemyAI(const sf::Texture & texture)
	: mTexture(texture)
	, mSprite()
{
	mSprite.setTexture(texture);
}

//------------------------------------------------------------------------------------------------------------------------

EnemyAI::~EnemyAI()
{

}

//------------------------------------------------------------------------------------------------------------------------

void EnemyAI::SetTexture(const sf::Texture & texture)
{
	mSprite.setTexture(texture);
}

//------------------------------------------------------------------------------------------------------------------------

void EnemyAI::SetPosition(const sf::Vector2f & vec)
{
	mSprite.setPosition(vec);
}

//------------------------------------------------------------------------------------------------------------------------

void EnemyAI::SetPosition(const float x, const float y)
{
	sf::Vector2f vec(x, y);
	SetPosition(vec);
}

//------------------------------------------------------------------------------------------------------------------------

void EnemyAI::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

//------------------------------------------------------------------------------------------------------------------------
