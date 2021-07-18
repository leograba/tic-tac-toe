# Source Files
SRC := src/
SRCS := $(wildcard $(SRC)*.cpp)

# Source Objects
OBJ := bin/
OBJS := $(patsubst $(SRC)%.cpp,$(OBJ)%.o,$(SRCS))
#OBJ = CApp.o CApp_OnInit.o

# Header Files
HEADERS := include/
DEPS = $(HEADERS)CApp.h

# Flags
SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LDFLAGS := $(shell sdl2-config --libs)

CFLAGS := $(CFLAGS) -Wall -Werror -pedantic -Wshadow -Wstrict-aliasing -Wstrict-overflow -I/usr/include
LDFLAGS := $(shell pkg-config --libs glesv2)

$(OBJ)%.o : $(SRC)%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS) $(SDL_CFLAGS) -I$(HEADERS)

capp: $(OBJS)
	$(CXX) -o $@ $^ $(CFLAGS) $(SDL_LDFLAGS) $(LDFLAGS)

install: capp
	mkdir -p $(WORKDIR)
	cp capp $(WORKDIR)/

clean:
	rm -f *.o
	rm -f $(OBJ)*.o
	rm -f capp
