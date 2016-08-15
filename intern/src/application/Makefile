# =====================================================
# Include directories
IDIR_APPLICATION = ../../../inc/application
IDIR_CORE        = ../../../inc/core
IDIR_GRAPHICS    = ../../../inc/graphics
IDIR_GUI         = ../../../inc/gui
IDIR_LOGIC       = ../../../inc/logic
IDIR_WORLD       = ../../../inc/world

# =====================================================
# Compiler information
CC = g++
CFLAGS  = -I$(IDIR_APPLICATION) -I$(IDIR_CORE) -I$(IDIR_GRAPHICS) -I$(IDIR_GUI) -I$(IDIR_LOGIC) -I$(IDIR_WORLD)
CFLAGS += -std=c++11

# =====================================================
# object and lib dir
ODIR = ../../build/obj
LDIR = ../../../lib

# =====================================================
# search for .cpp files in following dirs
VPATH = ../core:../graphics/:../gui/:../logic/:../world/

# =====================================================
# OS dependent libs
# here only glut stuff
OS = $(shell uname)
ifeq ($(OS), Darwin)
	LIBS = -framework OpenGL -framework GLUT
else ifeq ($(OS), Linux)
	LIBS = -lglut -lGLU -lGL
else
#	CC=i686-pc-mingw32-g++
#	CC=i686-w64-mingw32-g++
	CC=x86_64-w64-mingw32-g++
	LIBS = -lglut32 -lglu32 -lopengl32
#	LIBS = -lglut -lGLU -lGL
endif

# =====================================================
# dependency header files
_DEPS_APPLICATION = app_game_state.h app_load_map_state.h app_main.h app_main_menu_state.h app_play_state.h app_shutdown_state.h app_startup_state.h app_state.h app_unload_map_state.h snake_game.h snake.h
_DEPS_CORE        =
_DEPS_GRAPHICS    = view.h
_DEPS_GUI         =
_DEPS_LGOIC       =
_DEPS_WORLD       = field.h

DEPS  = $(patsubst %,$(IDIR_APPLICATION)/%,$(_DEPS_APPLICATION))
DEPS += $(patsubst %,$(IDIR_CORE)/%,$(_DEPS_CORE))
DEPS += $(patsubst %,$(IDIR_GRAPHICS)/%,$(_DEPS_GRAPHICS))
DEPS += $(patsubst %,$(IDIR_GUI)/%,$(_DEPS_GUI))
DEPS += $(patsubst %,$(IDIR_LOGIC)/%,$(_DEPS_LOGIC))
DEPS += $(patsubst %,$(IDIR_WORLD)/%,$(_DEPS_WORLD))

# =====================================================
# object files to be linked
_OBJ = main.o app_game_state.o app_load_map_state.o app_main.o app_main_menu_state.o app_play_state.o app_shutdown_state.o app_startup_state.o app_state.o app_unload_map_state.o snake_game.o snake.o view.o field.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	g++ -o $@ $^ $(CFLAGS) $(LIBS)

# =====================================================
# clean object dir
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~core $(INCDIR)/*~
