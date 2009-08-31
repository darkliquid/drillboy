// Include clanlib goodies
#include <ClanLib/core.h>
#include <ClanLib/display.h>

// Include class prototype
#include "game_engine.h"
#include "game_state.h"
#include "title_state.h"


GameEngine::GameEngine(CL_DisplayWindow& dw, CL_GraphicContext& gc, CL_InputDevice& id) {

  window = dw;
  graphics = gc;
  keyboard = id;
  running = true;
  // Connect the window close signal to the shutdown method
  window_close_slot = window.sig_window_close().connect(this, &GameEngine::shutdown);
  game_state = 0;
}

GameEngine::~GameEngine() {
  delete game_state;
}

bool GameEngine::run() {
  if(!game_state) {
    // deferencing pointer to this and passing engine by reference
    // at least, I'm pretty sure that's what I'm doing here
    game_state = new TitleState(&*this);
  }
  // check if the keyboard has escape pressed
  if(keyboard.get_keycode(CL_KEY_ESCAPE)) {
    // Output to console to say exit request received
    CL_Console::write_line("Escape pressed, exiting...");
    running = false; // get out of the infinite loop
  }

  // swap the graphics buffers as everything is drawn
  // off-screen by default (and rightly so)
  // this is controlled by the window, not the graphics context
  window.flip();

  // check gamestate to see if we need to transition to another one
  if(game_state->transitioning()) {
    CL_Console::write_line("Entering new state...");
    GameState* temp_state = game_state->next_state();
    delete game_state;
    game_state = temp_state;
  }

  // do stuff for current game state
  game_state->process();

  // Process events from the OS windowing system,
  // like closing the window, etc (GUESSING, not clear from docs)
  CL_DisplayMessageQueue::process();

  // This loop will take 100% CPU time as it's looping
  // as fast as the system will allow. Make it sleep a
  // bit so it's nicer to other processes
  CL_System::sleep(10);

  return running;
}

void GameEngine::shutdown() {
  CL_Console::write_line("Shutting down game engine...");
  running = false;
}
