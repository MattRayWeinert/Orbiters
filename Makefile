all: compile link

compile:
	g++ -c main.cpp game.cpp -Isrc\include

link:
	g++ main.o game.o -o main -Lsrc\lib -lsfml-graphics -lsfml-window -lsfml-system

clean:
	erase -f main *.o
