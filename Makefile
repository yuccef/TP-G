all: partie1 graph.o 

graph.o: graph.c graph.h
	gcc -c graph.c

partie1.o: partie1.c partie1.h
	gcc -c partie1.c

partie1 : partie1.c partie1.h graph.c graph.h 
	gcc -Wall -o partie1 partie1.c graph.c

debug: partie1.c partie1.h graph.c graph.h
	gcc -g -Wall -o partie1 partie1.c graph.c
	gdb partie1

clean:
	rm -f *.o partie1
