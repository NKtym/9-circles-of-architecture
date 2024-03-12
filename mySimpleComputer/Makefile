all: pr01

pr01: main.c sc_lib.a
	gcc -g -Wall -I /home/pavel/Документы/simplecomputer-1/include/ -o pr01 main.c sc_lib.a

sc_lib.a: sc*.o print*.o
	ar rcs sc_lib.a sc*.o print*.o

print*.o: print*.c
	gcc -g -c -I /home/pavel/Документы/simplecomputer-1/include/ print*.c

sc*.o: sc*.c
	gcc -g -c -I /home/pavel/Документы/simplecomputer-1/include/ sc*.c

.PHONY: clean

clean: sc_lib.a sc*.o print*.o
	rm sc*.o
	rm print*.o
	rm sc_lib.a
	rm pr01