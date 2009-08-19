#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include "game_engine.h"

class GameEngine;

class GameState {

  public:
    GameState(GameEngine*);
    virtual void process() = 0;
    GameState* next_state();
    bool transitioning();
  protected:
    bool change_state;
    GameState* new_state;
    GameEngine* engine;
};
  
#endif
