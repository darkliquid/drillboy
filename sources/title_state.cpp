#include "title_state.h"
#include "main_game_state.h"

// require core include to pull in basics
#include <ClanLib/core.h>
#include <ClanLib/display.h>


TitleState::TitleState(GameEngine* game_engine) : GameState(game_engine) {
  CL_Console::write_line("Entering title state...");
  engine->graphics.clear(CL_Colorf::white);
  CL_Console::write_line("Loading resources...");
  // Load a sprite from a jpeg
  clanlib_logo = CL_Sprite(engine->graphics, "assets/logo.jpg");
  CL_FontDescription desc;
  desc.set_typeface_name("tahoma");
  desc.set_height(50);
  font = CL_Font_System(engine->graphics, desc);
  option_selected = 0;
}

void TitleState::process() {
  process_input();
  engine->graphics.clear(CL_Colorf::white);
  clanlib_logo.draw(engine->graphics,
    (float) engine->graphics.get_width() - clanlib_logo.get_width(),
    (float) engine->graphics.get_height() - clanlib_logo.get_height()
  );
  font.draw_text(engine->graphics, 100, 100, "Start", CL_Colorf::black);
  font.draw_text(engine->graphics, 100, 200, "Quit", CL_Colorf::black);
  font.draw_text(engine->graphics, 70, (option_selected * 100) + 100, "*", CL_Colorf::black);
  return;
}

void TitleState::process_input() {
  if(engine->keyboard.get_keycode(CL_KEY_DOWN) && option_selected < 1) {
    option_selected++;
  }
  if(engine->keyboard.get_keycode(CL_KEY_UP) && option_selected > 0) {
    option_selected--;
  }
  if(engine->keyboard.get_keycode(CL_KEY_RETURN)) {
    if(option_selected == 0) {
      CL_Console::write_line("Starting main game...");
      new_state = new MainGameState(&*engine);
      change_state = true;
    }
    if(option_selected == 1) {
      CL_Console::write_line("Quit selected...");
      engine->shutdown();
    }
  }
}
