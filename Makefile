all:
	g++ -Isrc/include -Iengine -L src/lib -o main main.cpp engine/core.cpp -lmingw32 -lSDL2main -lSDL2