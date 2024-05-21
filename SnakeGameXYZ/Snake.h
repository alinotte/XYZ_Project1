#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "GameSettings.h"

namespace SnakeGame
{
	enum class SnakeDirection
	{
		Up = 0,
		Right,
		Down,
		Left,
	};

	struct Snake
	{
		Position position;
		float speed = 0.f;
		SnakeDirection direction;
		sf::Sprite sprite;
	};

	void InitSnake(Snake& snake, const sf::Texture& texture);
	void UpdateSnake(Snake& snake, float timeDelta);
	bool DetectSnakeCollisionWithScreenBorder(const Snake& snake);
	void DrawSnake(Snake& snake, sf::RenderWindow& window);
}

