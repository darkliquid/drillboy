#ifndef __TITLE_STATE_H__
#define __TITLE_STATE_H__

#include "game_state.h"
#include "game_engine.h"

#include <ClanLib/core.h>
#include <ClanLib/display.h>

class TitleState : public GameState {
  public:
    TitleState(GameEngine*);
    void process();
  private:
    void process_input();
    CL_Sprite clanlib_logo;
    CL_Font_System font;
    int option_selected;

};

#endif
