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

SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LDFLAGS := $(shell sdl2-config --libs)

$(OBJ)%.o : $(SRC)%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(SDL_CFLAGS) -I$(HEADERS)

capp: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(SDL_LDFLAGS)

install: capp
	mkdir -p $(WORKDIR)
	cp capp $(WORKDIR)/

clean:
	rm -f *.o
	rm -f $(OBJ)*.o
	rm -f capp
