STKFLAG=-lstk
SDLFLAG= -w -lSDL2 -lSDL2_image

all: piano

piano: piano.cpp
	g++ $^ $(SDLFLAG) $(STKFLAG) -o $@
clean:
	rm piano
