#include "title_state.h"

// require core include to pull in basics
#include <ClanLib/core.h>
#include <ClanLib/display.h>


TitleState::TitleState(GameEngine* game_engine) : GameState(game_engine) {
  CL_Console::write_line("Entering title state...");
  engine->graphics.clear(CL_Colorf::white);
  CL_Console::write_line("Loading resources...");
  // Load a sprite from a jpeg
  clanlib_logo = CL_Sprite(engine->graphics, "assets/logo.jpg");
}

void TitleState::process() {
  clanlib_logo.draw(engine->graphics,
    (float) engine->graphics.get_width() - clanlib_logo.get_width(),
    (float) engine->graphics.get_height() - clanlib_logo.get_height()
  );

  return;
}
