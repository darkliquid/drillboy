#include "main_game_state.h"

// require core include to pull in basics
#include <ClanLib/core.h>
#include <ClanLib/display.h>


MainGameState::MainGameState(GameEngine* game_engine) : GameState(game_engine) {
  CL_Console::write_line("Entering main game state...");

  engine->graphics.clear(CL_Colorf::black);
}

void MainGameState::process() {
//  engine->graphics.clear(CL_Colorf::black);
  return;
}
