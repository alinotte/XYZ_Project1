#include "Snake.h"
#include "GameSettings.h"

namespace SnakeGame
{
	void InitSnake(Snake& snake, const sf::Texture& texture)
	{
		// init snake position and state
		snake.position.x = (float)SCREEN_WIDTH / 2.f;
		snake.position.y = (float)SCREEN_HEIGHT / 2.f;
		snake.speed = INITIAL_SPEED;
		snake.direction = SnakeDirection::Up;

		// init sprite
		snake.sprite.setTexture(texture);
		snake.sprite.setOrigin(GetItemOrigin(snake.sprite, { 0.5f, 0.5f }));
		snake.sprite.setScale(GetSpriteScale(snake.sprite, { SNAKE_SIZE, SNAKE_SIZE }));
	}

	void UpdateSnake(Snake& snake, float timeDelta)
	{
		// changing direction
		switch (snake.direction)
		{
		case SnakeDirection::Up:
		{
			snake.position.y -= snake.speed * timeDelta;
			break;
		}
		case SnakeDirection::Right:
		{
			snake.position.x += snake.speed * timeDelta;
			break;
		}
		case SnakeDirection::Down:
		{
			snake.position.y += snake.speed * timeDelta;
			break;
		}
		case SnakeDirection::Left:
		{
			snake.position.x -= snake.speed * timeDelta;
			break;
		}
		}
	}

	bool DetectSnakeCollisionWithScreenBorder(const Snake& snake)
	{
		if (snake.position.x < 0.f || snake.position.x > (float)SCREEN_WIDTH)
		{
			return false;
		}
		if (snake.position.y < 0.f || snake.position.y > (float)SCREEN_HEIGHT)
		{
			return false;
		}
		return true;
	}

	void DrawSnake(Snake& snake, sf::RenderWindow& window)
	{
		snake.sprite.setPosition(OurVectorToSf(snake.position));

		const sf::Vector2f spriteScale = (GetSpriteScale(snake.sprite, { SNAKE_SIZE, SNAKE_SIZE }));

		// head sprite rotation
		switch (snake.direction)
		{
		case SnakeDirection::Up:
		{
			snake.sprite.setScale(spriteScale.x, spriteScale.y);
			snake.sprite.setRotation(-90.f);
			break;
		}
		case SnakeDirection::Right:
		{
			snake.sprite.setScale(spriteScale.x, spriteScale.y);
			snake.sprite.setRotation(0.f);
			break;
		}
		case SnakeDirection::Down:
		{
			snake.sprite.setScale(spriteScale.x, spriteScale.y);
			snake.sprite.setRotation(90.f);
			break;
		}
		case SnakeDirection::Left:
		{
			snake.sprite.setScale(-spriteScale.x, spriteScale.y);
			snake.sprite.setRotation(0.f);
			break;
		}
		}

		window.draw(snake.sprite);
	}
}