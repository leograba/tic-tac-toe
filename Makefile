DEPS = sdl2-learning.h
OBJ = sdl2-learning.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sdl2-learning: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

install: sdl2-learning
	mkdir -p $(WORKDIR)
	cp sdl2-learning $(WORKDIR)/

clean:
	rm -f *.o
	rm -f sdl2-learning
