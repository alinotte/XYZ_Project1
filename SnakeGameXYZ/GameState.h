#pragma once
#include "GameStatePlaying.h"
#include "GameStateGameOver.h"

namespace SnakeGame
{
	enum class GameStateType
	{
		None = 0,
		Playing,
		GameOver,
	};

	struct GameState
	{
		GameStateType type = GameStateType::None;
		void* data = nullptr;
		bool isExclusivelyVisible = false;
	};

	enum class GameStateChangeType
	{
		None = 0,
		Push,
		Pop,
		Switch,
	};

	void PushGameState(Game& game, GameStateType stateType, bool isExclusivelyVisible);
	void PopGameState(Game& game);
	void SwitchGameState(Game& game, GameStateType newState);
	void InitGameState(Game& game, GameState& state);
	void ShutdownGameState(Game& game, GameState& state);
	void HandleWindowEventGameState(Game& game, GameState& state, sf::Event& event);
	void UpdateGameState(Game& game, GameState& state, float timeDelta);
	void DrawGameState(Game& game, GameState& state, sf::RenderWindow& window);
}