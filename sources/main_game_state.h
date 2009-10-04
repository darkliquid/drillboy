#ifndef __MAIN_GAME_STATE_H__
#define __MAIN_GAME_STATE_H__

#include "game_state.h"
#include "game_engine.h"
#include "block_manager.h"

#include <ClanLib/core.h>
#include <ClanLib/display.h>

class MainGameState : public GameState {
  public:
    MainGameState(GameEngine*);
    void process();
  private:
    BlockManager play_field;

};

#endif
