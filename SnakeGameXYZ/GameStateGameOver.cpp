#include <assert.h>
#include "Game.h"
#include "GameStateGameOver.h"

namespace SnakeGame
{
	void InitGameStateGameOver(GameStateGameOverData& data, Game& game)
	{
		assert(data.font.loadFromFile("Resources/Fonts/PoetsenOne-Regular.ttf"));

		data.timeSinceGameOver = 0.f;

		data.gameOverText.setFont(data.font);
		data.gameOverText.setCharacterSize(48);
		data.gameOverText.setStyle(sf::Text::Bold);
		data.gameOverText.setFillColor(sf::Color::Red);
		data.gameOverText.setString("GAME OVER");
		data.gameOverText.setOrigin(GetItemOrigin(data.gameOverText, { 0.5f, 0.5f }));
	}

	void HandleGameStateGameOverWindowEvent(GameStateGameOverData& data, Game& game, const sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				SwitchGameState(game, GameStateType::Playing);
			}
			else if (event.key.code == sf::Keyboard::Escape)
			{
				SwitchGameState(game, GameStateType::None);
			}
		}
	}

	void UpdateGameStateGameOver(GameStateGameOverData& data, Game& game, float timeDelta)
	{
		data.timeSinceGameOver += timeDelta;

		sf::Color gameOverTextColor = (int)data.timeSinceGameOver % 2 ? sf::Color::Red : sf::Color::Yellow;
		data.gameOverText.setFillColor(gameOverTextColor);
	}

	void DrawGameStateGameOver(GameStateGameOverData& data, Game& game, sf::RenderWindow& window)
	{
		sf::Vector2f viewSize = window.getView().getSize();

		data.gameOverText.setPosition(viewSize.x / 2.f, viewSize.y / 2.f);
		window.draw(data.gameOverText);
	}
}