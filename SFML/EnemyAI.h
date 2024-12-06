#pragma once

#include <SFML/Graphics.hpp>
#include <string>

enum class EEnemy
{
    Ship,
    Ufo,
};

class EnemyAI : public sf::Drawable
{
public:
    //EnemyAI();
    EnemyAI(const EEnemy & enemyType);
    ~EnemyAI();

    void InitEnemy();                             // Initialize the enemy's texture and sprite
    void SetTexture(const std::string & file);    // Load a texture from a file and set it
    void SetPosition(const sf::Vector2f & vec);   // Set position using a vector
    void SetPosition(const float x, const float y); // Set position using x and y values

protected:
    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

private:
    sf::Texture mTexture;
    sf::Sprite mSprite;
    EEnemy mEnemyType;
};
