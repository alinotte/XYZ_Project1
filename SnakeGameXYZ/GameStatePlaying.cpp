#include <assert.h>
#include "Game.h"
#include "GameStatePlaying.h"

namespace SnakeGame
{
	void InitGameStatePlaying(GameStatePlayingData& data, Game& game)
	{
		assert(data.snakeTexture.loadFromFile("Resources/Snake/SnakeHead.png"));
		assert(data.appleTexture.loadFromFile("Resources/Apple/Apple.png"));
		assert(data.font.loadFromFile("Resources/Fonts/PoetsenOne-Regular.ttf"));

		InitSnake(data.snake, data.snakeTexture);

		InitApple(data.apple, data.appleTexture);
		ResetAppleState(data.apple);

		data.numEatenApples = 0;
	}

	void UpdateGameStatePlaying(GameStatePlayingData& data, Game& game, float timeDelta)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			data.snake.direction = SnakeDirection::Up;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			data.snake.direction = SnakeDirection::Right;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			data.snake.direction = SnakeDirection::Down;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			data.snake.direction = SnakeDirection::Left;
		}

		UpdateSnake(data.snake, timeDelta);

		if (!data.apple.isEaten)
		{
			float dx = data.snake.position.x - data.apple.position.x;
			float dy = data.snake.position.y - data.apple.position.y;
			float distance = sqrt(dx * dx + dy * dy);
			if (distance < (SNAKE_SIZE + APPLE_SIZE) / 2)
			{
				++data.numEatenApples;
				ResetAppleState(data.apple);
			}
		}

		if (!DetectSnakeCollisionWithScreenBorder(data.snake))
		{
			PushGameState(game, GameStateType::GameOver, false);
		}
	}

	void DrawGameStatePlaying(GameStatePlayingData& data, Game& game, sf::RenderWindow& window)
	{
		DrawSnake(data.snake, window);
		DrawApple(data.apple, window);
	}
}


