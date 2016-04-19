STKFLAG=-lstk
SDLFLAG=-lSDL -lSDL2_image

all: piano

piano: piano.cpp
	g++ $^ $(SDLFLAG) $(STKFLAG)-o $@
clean:
	rm piano
