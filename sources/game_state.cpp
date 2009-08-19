#include "game_engine.h"
#include "game_state.h"

GameState::GameState(GameEngine* game_engine) {
  engine = game_engine;
  change_state = false;
}

GameState* GameState::next_state() {
  return new_state;
}

bool GameState::transitioning() {
  return change_state;
}
