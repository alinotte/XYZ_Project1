#pragma once
#include "SFML/Graphics.hpp"
#include "Apple.h"
#include "Snake.h"

namespace SnakeGame
{
	struct Game;

	struct GameStatePlayingData
	{
		sf::Texture snakeTexture;
		sf::Texture appleTexture;
		
		Snake snake;
		Apple apple;
		int numEatenApples = 0;

		sf::Font font;
		sf::Text scoreText;
		sf::Text inputHintText;
	};

	void InitGameStatePlaying(GameStatePlayingData& data, Game& game);
	void UpdateGameStatePlaying(GameStatePlayingData& data, Game& game, float timeDelta);
	void DrawGameStatePlaying(GameStatePlayingData& data, Game& game, sf::RenderWindow& window);
}