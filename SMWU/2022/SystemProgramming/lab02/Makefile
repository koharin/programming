all: lineprint

lineprint: header.h main.o parse.o table.o
	gcc -o lineprint main.o parse.o table.o

main.o: header.h main.c
	gcc -c main.c

parse.o: header.h parse.c
	gcc -c parse.c

table.o: header.h table.c
	gcc -c table.c

clean:
	rm lineprint *.o
