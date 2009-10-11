// Include clanlib goodies
#include <ClanLib/core.h>
#include <ClanLib/display.h>

// display types
#include <ClanLib/gl1.h> // required to use gl1 render target
#include <ClanLib/sdl.h> // required for sdl target
#include <ClanLib/gdi.h> // required for gdi target
#include <ClanLib/gl.h>  // required ofr gl2 target

// Include class prototype
#include "game_runner.h"
#include "game_engine.h"

int GameRunner::main(const std::vector<CL_String> &args) {
  // Initialise clanlib by instanciating these classes.
  // when the get destroyed after scope goes away, they clean
  // themselves up (I think) so no need to deinitialise.
  // We never actually use these variables again.

  CL_SetupCore setup_core;
  CL_SetupDisplay setup_display;

  std::vector<CL_String> my_args = args;

  CL_String device = "GL";
  for(std::vector<CL_String>::iterator arg = my_args.begin(); arg != my_args.end(); ++arg) {
    CL_Console::write_line(*arg);
    if(*arg == "-d") {
      device = *++arg;
    }
  }

  CL_Console::write_line(device);


  // setup clanlib correctly (doesn't work)

  CL_SetupGL* setup_gl = 0;
  CL_SetupGL1* setup_gl1 = 0;
  CL_SetupSDL* setup_sdl = 0;
  CL_SetupGDI* setup_gdi = 0;

  if(device == "GL") {
     setup_gl = new CL_SetupGL();
  }
  if(device == "GL1") {
     setup_gl1 = new CL_SetupGL1();
  }
  if(device == "SDL") {
     setup_sdl = new CL_SetupSDL();
  }
  if(device == "GDI") {
     setup_gdi = new CL_SetupGDI();
  }


  // command line argument handling
  //CL_CommandLine argp;
  //argp.add_doc("Play Drillboy!");
  //argp.add_option('d', "device", "DEVICE", "Choose a device from GL1, GL, SDL or GDI");
  //argp.parse_args(args);

  //CL_SetupGL1 setup_gl1; // use gl1 as opengl2 target breaks for me
//  CL_SetupSDL setup_sdl; // use sdl as render target
  //CL_SetupGDI setup_gdi; // use gdi as render target
  //CL_SetupGL setup_gl;

  try {
    // Set the window description
    CL_DisplayWindowDescription desc;
    desc.set_title("Drillboy");
    desc.set_size(CL_Size(800, 600), true);

    // Lets actually make a window now called Drillboy 800x600
    CL_DisplayWindow window(desc);

    // Grab the graphics context so we have a handle to call
    // drawing functions on
    CL_GraphicContext graphics = window.get_gc();

    // Grab the keyboard so we can ask it about key presses
    CL_InputDevice keyboard = window.get_ic().get_keyboard();

    // Tell console (as in, text-based debug output) we are good to go
    CL_Console::write_line("ClanLib init complete...");

    // Before game loop begins, set screen to black via graphics context
    graphics.clear(CL_Colorf::black); // shortcut for CL_Colorf c(0,0,0)

    GameEngine engine(window, graphics, keyboard);

    bool running = true;

    // infinite loop to run the game
    while(running) {
      // Run the game engine
      running = engine.run();
    }

    if(setup_gl) delete setup_gl;
    if(setup_gl1) delete setup_gl1;
    if(setup_sdl) delete setup_sdl;
    if(setup_gdi) delete setup_gdi;

    // if we're this far, game finished running successfully, bye bye
    return 0;
  } catch(CL_Exception exception) {
    // output the exception's message
    CL_Console::write_line("ClanLib Exception caught:");
    CL_Console::write_line(exception.message);

    // Display the stack trace associated with the exception (it's an array of strings)
    std::vector<CL_String> stacktrace = exception.get_stack_trace();
    // if there is a stacktrace (because it has at least 1 line)
    // then iterate through the vector and output each line
    if (stacktrace.size() > 0) {
      CL_Console::write_line("Stack Trace:");
      for(std::vector<CL_String>::iterator line = stacktrace.begin();
          line != stacktrace.end(); ++line) {
        CL_Console::write_line(*line);
      }
    }

    return -1;
  }
}
