all: main.o IntVector.o
	gcc -Wall main.c IntVector -o main 
main.o: main.c
	gcc -Wall -c main.c -o main
IntVector.o: IntVector.c
	gcc -Wall -c IntVector.c -o IntVector
