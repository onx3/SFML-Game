#include "EnemyAI.h"
#include "cassert"

EnemyAI::EnemyAI()
	: mTexture()
	, mSprite()
	, mEnemyType()
{

}

//------------------------------------------------------------------------------------------------------------------------

EnemyAI::EnemyAI(const EEnemy & enemyType)
	: mTexture()
	, mSprite()
	, mEnemyType(enemyType)
{
	InitEnemy();
}

//------------------------------------------------------------------------------------------------------------------------

EnemyAI::~EnemyAI()
{

}

//------------------------------------------------------------------------------------------------------------------------

void EnemyAI::InitEnemy()
{
	std::string file;
	switch (mEnemyType)
	{
		case (EEnemy::Ship):
			file = "Art/enemyShip.png";
			assert(mTexture.loadFromFile(file));
			mSprite.setTexture(mTexture);
			break;

		case (EEnemy::Ufo):
			file = "Art/enemyUFO.png";
			assert(mTexture.loadFromFile(file));
			mSprite.setTexture(mTexture);
			break;
	}
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
// EOF
//------------------------------------------------------------------------------------------------------------------------