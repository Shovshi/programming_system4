all:
	gcc -g main.c graph.c graph.h -o graph

clean:
	rm  graph