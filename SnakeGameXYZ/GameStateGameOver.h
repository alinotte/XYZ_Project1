#pragma once
#include "SFML/Graphics.hpp"

namespace SnakeGame
{
	struct Game;

	struct GameStateGameOverData
	{
		sf::Font font;
		sf::Text gameOverText;
		sf::Text hintText;
		sf::Text recordsTableText;

		float timeSinceGameOver = 0.f;
	};
	void InitGameStateGameOver(GameStateGameOverData& data, Game& game);
	void HandleGameStateGameOverWindowEvent(GameStateGameOverData& data, Game& game, const sf::Event& event);
	void UpdateGameStateGameOver(GameStateGameOverData& data, Game& game, float timeDelta);
	void DrawGameStateGameOver(GameStateGameOverData& data, Game& game, sf::RenderWindow& window);
}