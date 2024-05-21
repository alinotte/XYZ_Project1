#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Apple.h"
#include "GameSettings.h"
#include "GameState.h"


namespace SnakeGame 
{
	struct Game
	{
		std::vector<GameState> gameStateStack;
		GameStateChangeType gameStateChangeType;
		GameStateType pendingGameStateType;
		bool pendingGameStateIsExclusivelyVisible;
	};

	void InitGame(Game& game);
	void HandleWindowEvents(Game& game, sf::RenderWindow& window);
	bool UpdateGame(Game& game, float timeDelta);
	void DrawGame(Game& game, sf::RenderWindow& window);
	void ShutdownGame(Game& game);
}