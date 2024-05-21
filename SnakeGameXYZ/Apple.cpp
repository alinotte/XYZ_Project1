#include "Apple.h"
#include "GameSettings.h"

namespace SnakeGame
{
	void InitApple(Apple& apple, const sf::Texture& texture)
	{
		// init sprite
		apple.sprite.setTexture(texture);
		apple.sprite.setOrigin(GetItemOrigin(apple.sprite, { 0.5f,0.5f }));
		apple.sprite.setScale(GetSpriteScale(apple.sprite, { APPLE_SIZE, APPLE_SIZE }));
	}

	void MarkAppleAsEaten(Apple& apple)
	{
		apple.isEaten = true;
	}

	void ResetAppleState(Apple& apple)
	{
		// init apple state
		apple.position.x = (float)(rand() % SCREEN_WIDTH);
		apple.position.y = (float)(rand() % SCREEN_HEIGHT);
		apple.isEaten = false;
	}

	void DrawApple(Apple& apple, sf::RenderWindow& window)
	{
		if (apple.isEaten)
		{
			return;
		}

		apple.sprite.setPosition(OurVectorToSf(apple.position));
		window.draw(apple.sprite);
	}
}