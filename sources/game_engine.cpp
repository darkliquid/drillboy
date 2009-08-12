// Include clanlib goodies
#include <ClanLib/core.h>
#include <ClanLib/display.h>

// Include class prototype
#include "game_engine.h"

GameEngine::GameEngine(CL_DisplayWindow& dw, CL_GraphicContext& gc, CL_InputDevice& id) {

  window = dw;
  graphics = gc;
  keyboard = id;
  running = true;

}

bool GameEngine::run() {
	  
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

	// Process events from the OS windowing system,
	// like closing the window, etc (GUESSING, not clear from docs)
	CL_DisplayMessageQueue::process();

	// This loop will take 100% CPU time as it's looping
	// as fast as the system will allow. Make it sleep a
	// bit so it's nicer to other processes
	CL_System::sleep(10);
	
  return running;
}
