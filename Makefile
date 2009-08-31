BIN=drillboy

OBJF=\
	sources/main.o \
	sources/game_runner.o \
	sources/game_engine.o \
	sources/game_state.o \
	sources/title_state.o \
	sources/main_game_state.o

LIBS=clanCore clanDisplay clanApp clanSDL

include ../Makefile.conf

