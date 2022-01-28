/// <summary>
/// @author Daniel Mendioza Serment, c00274269
/// @date January 2022
/// </summary>

#include "Game.h"
#include <iostream>



/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 1200U, 900U, 32U }, "Simon Says 2k22" },
	m_redButton{ sf::Vector2f{ 200.0f, 200.0f } },
	m_blueButton{ sf::Vector2f{ 200.0f, 200.0f } },
	m_yellowButton{sf::Vector2f{ 200.0f, 200.0f } },
	m_greenButton{sf::Vector2f{ 200.0f, 200.0f } },
	m_exitGame{false} //when true game will exit
{
	setupSimonSaysButtons();
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}
/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}
/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
}
/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);
	m_window.draw(m_redButton);
	m_window.draw(m_blueButton);
	m_window.draw(m_yellowButton);
	m_window.draw(m_greenButton);
	m_window.display();
}

void Game::setupSimonSaysButtons()
{
	m_redButton.setFillColor(sf::Color(249, 7, 22, 255));
	m_redButton.setPosition(570.0f, 30.0f);

	m_blueButton.setFillColor(sf::Color(43, 115, 240, 255));
	m_blueButton.setPosition(570.0f, 250.0f);

	m_yellowButton.setFillColor(sf::Color(255, 233, 33, 255));
	m_yellowButton.setPosition(790.0f, 30.0f);

	m_greenButton.setFillColor(sf::Color(50, 205, 50, 255));
	m_greenButton.setPosition(790.0f, 250.0f);

	//this next comment is for a later use
	/*m_yellowButton.setPointCount(5);
	m_yellowButton.setRadius(100.0f);
	m_yellowButton.setFillColor(sf::Color(255, 242, 0, 255));
	m_yellowButton.setPosition(790.0f, 30.0f);*/

}
