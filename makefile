all: graph

graph: main.o graph.o
	gcc -Wall -g -o graph main.o graph.o

main.o: main.c graph.c
	gcc -Wall -g -c main.c

graph.o: graph.c graph.h
	gcc -Wall -g -c graph.c
clean:
	rm  graph *.o