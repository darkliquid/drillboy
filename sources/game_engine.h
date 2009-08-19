#ifndef __GAME_ENGINE_H__
#define __GAME_ENGINE_H__

// require core include to pull in basics
#include <ClanLib/core.h>
#include <ClanLib/display.h>

#include "game_state.h"

class GameState;

class GameEngine {

  public:
    GameEngine(CL_DisplayWindow&, CL_GraphicContext&, CL_InputDevice&);
    ~GameEngine();
    bool run();
    void shutdown();
    CL_DisplayWindow window;
    CL_GraphicContext graphics;
    CL_InputDevice keyboard;
  private:
    bool running;
    GameState* game_state;
    CL_Slot window_close_slot;
    
};

#endif
