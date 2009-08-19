#include "title_state.h"

// require core include to pull in basics
#include <ClanLib/core.h>
#include <ClanLib/display.h>


TitleState::TitleState(GameEngine* game_engine) : GameState(game_engine) {
  CL_Console::write_line("Entering title state...");
  engine->graphics.clear(CL_Colorf::white);
}

void TitleState::process() {
  CL_Console::write_line("This would be drawing stuff for the title screen");
  return;
}
