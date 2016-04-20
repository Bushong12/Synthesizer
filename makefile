STKFLAG=-lstk
SDLFLAG= -w -lSDL2 -lSDL2_image

all: piano

piano: piano.cpp
	g++ piano.cpp $(SDLFLAG) $(STKFLAG) -o piano

clean:
	rm piano
