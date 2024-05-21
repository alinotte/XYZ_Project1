#pragma once
#include <SFML/Graphics.hpp>
#include "GameSettings.h"
#include "Math.h"

namespace SnakeGame
{
	struct Apple
	{
		Position position;
		sf::Sprite sprite;
		bool isEaten = false;
	};

	void InitApple(Apple& apple, const sf::Texture& texture);
	void MarkAppleAsEaten(Apple& apple);
	void ResetAppleState(Apple& apple);
	void DrawApple(Apple& apple, sf::RenderWindow& window);
}

