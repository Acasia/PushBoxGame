all:exc_game

exc_game:Game.o main.o
	g++ -W -Wall -o exc_game Game.o main.o -lncursesw

Game.o:Game.cpp
	g++ -W -Wall -c -o Game.o Game.cpp

main.o:main.cpp
	g++ -W -Wall -c -o main.o main.cpp
