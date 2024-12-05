#include "Game.h"

Game::Game()
    : mpWindow(nullptr)
    , mEvent()
    , mEnemy()
{
    InitWindow();
    InitEnemies();
}

//------------------------------------------------------------------------------------------------------------------------

Game::~Game()
{
    delete mpWindow;
}

//------------------------------------------------------------------------------------------------------------------------

void Game::PollEvents()
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

void Game::Update()
{
    PollEvents();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        auto relativeMousePos = sf::Mouse::getPosition(*mpWindow);
        std::cout << "Mouse pos : " << sf::Mouse::getPosition(*mpWindow).x << " " << sf::Mouse::getPosition(*mpWindow).y << "\n";
    }
}

//------------------------------------------------------------------------------------------------------------------------

void Game::Render()
{
    mpWindow->clear(sf::Color::Cyan);

    // Draw the Game
    mpWindow->draw(mEnemy);

    mpWindow->display(); // Renderer is done keep at the end.
}

//------------------------------------------------------------------------------------------------------------------------

void Game::InitEnemies()
{
    mEnemy.setPosition(100.f, 100.f);
    mEnemy.setSize(sf::Vector2f(50.f, 50.f));
    mEnemy.setFillColor(sf::Color::Magenta);
    mEnemy.setOutlineColor(sf::Color::Black);
    mEnemy.setOutlineThickness(1.f);
}

//------------------------------------------------------------------------------------------------------------------------

void Game::InitWindow()
{
    mpWindow = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Game", sf::Style::Default);
    mpWindow->setFramerateLimit(240);
}

//------------------------------------------------------------------------------------------------------------------------
// EOF
//------------------------------------------------------------------------------------------------------------------------