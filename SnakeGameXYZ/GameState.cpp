#include <assert.h>
#include "Game.h"
#include "GameState.h"


namespace SnakeGame
{
	void PushGameState(Game& game, GameStateType stateType, bool isExclusivelyVisible)
	{
		game.pendingGameStateType = stateType;
		game.pendingGameStateIsExclusivelyVisible = isExclusivelyVisible;
		game.gameStateChangeType = GameStateChangeType::Push;
	}

	void PopGameState(Game& game)
	{
		game.pendingGameStateType = GameStateType::None;
		game.pendingGameStateIsExclusivelyVisible = false;
		game.gameStateChangeType = GameStateChangeType::Pop;
	}

	void SwitchGameState(Game& game, GameStateType newState)
	{
		game.pendingGameStateType = newState;
		game.pendingGameStateIsExclusivelyVisible = false;
		game.gameStateChangeType = GameStateChangeType::Switch;
	}

	void InitGameState(Game& game, GameState& state)
	{
		switch (state.type)
		{
		case GameStateType::Playing:
		{
			state.data = new GameStatePlayingData();
			InitGameStatePlaying(*(GameStatePlayingData*)state.data, game);
			break;
		}
		case GameStateType::GameOver:
		{
			state.data = new GameStateGameOverData();
			InitGameStateGameOver(*(GameStateGameOverData*)state.data, game);
			break;
		}
		default:
			assert(false);
			break;
		}
	}

	void ShutdownGameState(Game& game, GameState& state)
	{
		switch (state.type)
		{
		case GameStateType::Playing:
		{
			delete (GameStatePlayingData*)state.data;
			break;
		}
		case GameStateType::GameOver:
		{
			delete (GameStateGameOverData*)state.data;
			break;
		}
		default:
			assert(false);
			break;
		}

		state.data = nullptr;
	}

	void HandleWindowEventGameState(Game& game, GameState& state, sf::Event& event)
	{
		switch (state.type)
		{
		case GameStateType::Playing:
		{
			//HandleGameStatePlayingWindowEvent(*(GameStatePlayingData*)state.data, game, event);
			break;
		}
		case GameStateType::GameOver:
		{
			HandleGameStateGameOverWindowEvent(*(GameStateGameOverData*)state.data, game, event);
			break;
		}
		default:
			assert(false);
			break;
		}
	}

	void UpdateGameState(Game& game, GameState& state, float timeDelta)
	{
		switch (state.type)
		{
		case GameStateType::Playing:
		{
			UpdateGameStatePlaying(*(GameStatePlayingData*)state.data, game, timeDelta);
			break;
		}
		case GameStateType::GameOver:
		{
			UpdateGameStateGameOver(*(GameStateGameOverData*)state.data, game, timeDelta);
			break;
		}
		default:
			assert(false);
			break;
		}
	}

	void DrawGameState(Game& game, GameState& state, sf::RenderWindow& window)
	{
		switch (state.type)
		{
		case GameStateType::Playing:
		{
			DrawGameStatePlaying(*(GameStatePlayingData*)state.data, game, window);
			break;
		}
		case GameStateType::GameOver:
		{
			DrawGameStateGameOver(*(GameStateGameOverData*)state.data, game, window);
			break;
		}
		default:
			assert(false);
			break;
		}
	}
}