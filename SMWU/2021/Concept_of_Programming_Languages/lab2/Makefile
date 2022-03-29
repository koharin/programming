all: lab2

lab2: front.o parser.o
	gcc -o lab2 front.o parser.o

front.o: front.h front.c
	gcc -c -o front.o front.c

parse.o: parser.h parser.c
	gcc -c -o parser.o parser.c

clean: 
	rm lab2 *.o
