// require core include to pull in basics
#include <ClanLib/core.h>
#include <ClanLib/display.h>

class GameEngine {

  public:
    GameEngine(CL_DisplayWindow&, CL_GraphicContext&, CL_InputDevice&);
    bool run();
  private:
    bool running;
    CL_DisplayWindow window;
    CL_GraphicContext graphics;
    CL_InputDevice keyboard;
    
};
