#ifndef __TITLE_STATE_H__
#define __TITLE_STATE_H__

#include "game_state.h"
#include "game_engine.h"

class TitleState : public GameState {
  public:
    TitleState(GameEngine*);
    void process();
};

#endif
