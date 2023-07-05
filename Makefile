CC = g++
CFLAGS = -Wall -Isrc\include -Isrc\engine -Lsrc\lib
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
CPPFILES = src/engine/texturemanager.cpp src/engine/core.cpp src/engine/object2d.cpp main.cpp
OBJFILES = texturemanager.o core.o main.o
TARGET = main

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(CPPFILES) $(LDFLAGS)
