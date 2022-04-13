## Compiler
CC=g++
## Linker
LD=$(CC)
## Flags

DEPS = objects.h

CPPFLAGS = -Wall -g -DLINUX
LFLAGS = -lglut -L/usr/lib -L/usr/X11R6/lib -lXi -lXmu -lGL -lGLU -lm

TARGETS = $(PROGFILES:.cpp=)

PROGFILES = \
        main.cpp \
        $(NULL)

targets default: $(TARGETS)

$(PROGFILES:.cpp=): main.o skybox.o room.o
	$(CC) -o room main.o skybox.o room.o ${LFLAGS}

depend :
	makedepend ${PROGFILES} $(DEPS)
# DO NOT DELETE
