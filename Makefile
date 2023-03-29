all: test graph.o 

graph.o: graph.c graph.h
	gcc -c graph.c

test.o: test.c test.h
	gcc -c test.c

test : test.c test.h graph.c graph.h 
	gcc -Wall -o test test.c graph.c

debug: test.c test.h graph.c graph.h
	gcc -g -Wall -o test test.c graph.c
	gdb test

clean:
	rm -f *.o test
