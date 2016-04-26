PROGRAMS = sine sineosc foursine
RM = /bin/rm
SRC_PATH = ../../src
OBJECT_PATH = Release
vpath %.o $(OBJECT_PATH)

INCLUDE = 
ifeq ($(strip $(INCLUDE)), )
	INCLUDE = ../../include
endif
vpath %.h $(INCLUDE)

CC       = g++
DEFS     =   -DHAVE_GETTIMEOFDAY -D__MACOSX_CORE__
DEFS    += -D__LITTLE_ENDIAN__
CFLAGS   = -O3 -Wall -w
CFLAGS  += -I$(INCLUDE) -I$(INCLUDE)/../src/include
LIBRARY = -lpthread -framework CoreAudio -framework CoreFoundation -framework CoreMidi -lSDL2 -lSDL2_image -lstk

REALTIME = yes
ifeq ($(REALTIME),yes)
#  PROGRAMS += play record audioprobe midiprobe duplex inetIn inetOut rtsine playscales crtsine bethree controlbee threebees playsmf grains
	PROGRAMS += main
endif

RAWWAVES = 
ifeq ($(strip $(RAWWAVES)), )
	RAWWAVES = ../../rawwaves/
endif
DEFS    += -DRAWWAVE_PATH=\"$(RAWWAVES)\"

%.o : $(SRC_PATH)/%.cpp $(OBJECT_PATH)/.placeholder
	$(CC) $(CFLAGS) $(DEFS) -c $(<) -o $(OBJECT_PATH)/$@

%.o : ../../src/include/%.cpp $(OBJECT_PATH)/.placeholder
	$(CC) $(CFLAGS) $(DEFS) -c $(<) -o $(OBJECT_PATH)/$@

all : $(PROGRAMS)

$(OBJECT_PATH)/.placeholder:
	mkdir -vp $(OBJECT_PATH)
	touch $(OBJECT_PATH)/.placeholder

$(OBJECTS) : Stk.h

clean : 
	$(RM) -f $(OBJECT_PATH)/*.o
	$(RM) -f $(PROGRAMS) *.exe
	$(RM) -fR *~ *.dSYM

distclean: clean
	$(RM) Makefile

strip : 
	strip $(PROGRAMS)

main.o: main.cpp piano.h key.h sharp.h
	$(CC) $(LDFLAGS) $(CFLAGS) -w -lSDL2 -lSDL2_image -c main.cpp

main: main.o Stk.o SineWave.o RtWvOut.o RtAudio.o Mutex.o
	$(CC) $(LDFLAGS) -w -lSDL2 -lSDL2_image $(CFLAGS) $(DEFS) -o main main.cpp $(OBJECT_PATH)/Stk.o $(OBJECT_PATH)/SineWave.o $(OBJECT_PATH)/RtWvOut.o $(OBJECT_PATH)/RtAudio.o $(OBJECT_PATH)/Mutex.o $(LIBRARY)

sine: sine.cpp Stk.o SineWave.o FileWrite.o FileWvOut.o
	$(CC) $(LDFLAGS) $(CFLAGS) $(DEFS) -o sine sine.cpp $(OBJECT_PATH)/Stk.o $(OBJECT_PATH)/SineWave.o $(OBJECT_PATH)/FileWrite.o $(OBJECT_PATH)/FileWvOut.o $(LIBRARY)

sineosc: sineosc.cpp Stk.o FileRead.o FileWvIn.o FileLoop.o FileWrite.o FileWvOut.o
	$(CC) $(LDFLAGS) $(CFLAGS) $(DEFS) -o sineosc sineosc.cpp $(OBJECT_PATH)/Stk.o $(OBJECT_PATH)/FileWrite.o $(OBJECT_PATH)/FileRead.o $(OBJECT_PATH)/FileWvIn.o $(OBJECT_PATH)/FileWvOut.o $(OBJECT_PATH)/FileLoop.o $(LIBRARY)

foursine: foursine.cpp Stk.o SineWave.o FileWrite.o FileWvOut.o
	$(CC) $(LDFLAGS) $(CFLAGS) $(DEFS) -o foursine foursine.cpp $(OBJECT_PATH)/Stk.o $(OBJECT_PATH)/SineWave.o $(OBJECT_PATH)/FileWrite.o $(OBJECT_PATH)/FileWvOut.o $(LIBRARY)

