## Compiler
CC=g++
## Linker
LD=$(CC)
## Flags

DEPS = objects.h

CPPFLAGS = -Wall -g -DLINUX
LFLAGS = -lglut -L/usr/lib -L/usr/X11R6/lib -lXi -lXmu -lGL -lGLU -lm

TARGETS = $(PROGFILES:.cpp=)
TARGET = room

PROGFILES = \
        main.cpp \
        $(NULL)

targets default: $(TARGETS)

$(PROGFILES:.cpp=): main.o skybox.o room.o ComputerScreen.o std_image_implementation.o
	$(CC) -o $(TARGET) main.o skybox.o room.o ComputerScreen.o std_image_implementation.o ${LFLAGS}

depend :
	makedepend ${PROGFILES} $(DEPS)

clean:
	rm $(TARGET) *.o
