CC = g++
CFLAGS = -Wall -Isrc\include -Isrc\engine -Lsrc\lib
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
ENG = src/engine/
CPPFILES = $(ENG)texturemanager.cpp $(ENG)core.cpp $(ENG)object2d.cpp $(ENG)keyboardinput.cpp main.cpp
TARGET = main

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(CPPFILES) $(LDFLAGS)
