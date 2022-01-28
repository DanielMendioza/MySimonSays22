/// <summary>
/// author Daniel Mendioza Serment January 2022
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	void setupSimonSaysButtons();

	

	sf::RenderWindow m_window; // main SFML window
	sf::RectangleShape m_redButton;// makes existence of red button a reality
	sf::RectangleShape m_blueButton;// makes existence of blue button not just a fantasy
	sf::RectangleShape m_yellowButton;// makes existence of yellow button 
	sf::RectangleShape m_greenButton;//makes existence of green button , do you feel like a god?
	//sf::CircleShape m_yellowButton;
	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

