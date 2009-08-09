// basic headers needed to start clanlib
#include <ClanLib/core.h>
#include <ClanLib/application.h>

// Main game control class
#include "game_runner.h"

// set cross platform entry point into game
// by providing the app function a reference
// to our game runner main function
CL_ClanApplication app(&GameRunner::main);

