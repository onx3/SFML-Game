#include "GameManager.h"
#include "EnemyAI.h"

GameManager::GameManager()
    : mpWindow(nullptr)
    , mEvent()
    , mEnemyTextures()
    , mEnemies()
    , mBackgroundTexture()
    , mBackgroundSprite()
{
    InitWindow();
    InitEnemies();
}

//------------------------------------------------------------------------------------------------------------------------

GameManager::~GameManager()
{
    delete mpWindow;
}

//------------------------------------------------------------------------------------------------------------------------

void GameManager::PollEvents()
{
    while (mpWindow->pollEvent(mEvent))
    {
        switch (mEvent.type)
        {
            case sf::Event::Closed:
            {
                mpWindow->close();
                break;
            }
            case sf::Event::KeyPressed:
            {
                if (mEvent.key.code == sf::Keyboard::Escape)
                {
                    mpWindow->close();
                }
                break;
            }
        }
    }
}

//------------------------------------------------------------------------------------------------------------------------

void GameManager::Update()
{
    PollEvents();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        auto relativeMousePos = sf::Mouse::getPosition(*mpWindow);
        std::cout << "Mouse pos : " << sf::Mouse::getPosition(*mpWindow).x << " " << sf::Mouse::getPosition(*mpWindow).y << "\n";
    }
}

//------------------------------------------------------------------------------------------------------------------------

void GameManager::Render()
{
    mpWindow->clear();

    // Draw the Game
    mpWindow->draw(mBackgroundSprite);
    
    for (auto enemy : mEnemies)
    {
        mpWindow->draw(enemy);
    }

    mpWindow->display(); // Renderer is done keep at the end.
}

//------------------------------------------------------------------------------------------------------------------------

void GameManager::InitEnemies()
{
    mEnemies.push_back(EnemyAI());

    std::string file = "Art/enemyUFO.png";
    sf::Texture texture;
    if (!texture.loadFromFile(file))
    {
        // Handle error
        std::cout << "Can't load the file";
    }

    mEnemyTextures.push_back(texture);
    mEnemies.back().SetTexture(mEnemyTextures.back());
    mEnemies.back().SetPosition(100.f, 100.f);
}

//------------------------------------------------------------------------------------------------------------------------

void GameManager::InitWindow()
{
    mpWindow = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Game", sf::Style::Default);
    mpWindow->setFramerateLimit(240);

    std::string file = "Art/Background/starBackground.png";
    if (!mBackgroundTexture.loadFromFile(file))
    {
        // Handle error
        std::cout << "Can't load the file : " << file;
    }
    mBackgroundSprite.setTexture(mBackgroundTexture);
    // Scale to window size
    mBackgroundSprite.setScale(float(mpWindow->getSize().x) / mBackgroundTexture.getSize().x, float(mpWindow->getSize().y) / mBackgroundTexture.getSize().y);
}

//------------------------------------------------------------------------------------------------------------------------
// EOF
//------------------------------------------------------------------------------------------------------------------------