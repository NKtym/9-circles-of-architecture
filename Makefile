all: mySimpleComputer/sc_lib.a myTerm/mt_lib.a console/cons_lib.a console/console

test: console/test.o
	gcc console/test.o -o console/test
test.o: console/test.c
	gcc -c console/test.c

console/console: console/console.c mySimpleComputer/*.c myTerm/*.c console/print*.c
	gcc -g -I include/ -o console/console console/console.c mySimpleComputer/sc*.c myTerm/mt*.c console/print*.c

#console/console: console/console.c mySimpleComputer/sc_lib.a myTerm/mt_lib.a console/cons_lib.a
#	gcc -g -Wall -I include/ -o console/console console/console.c mySimpleComputer/sc_lib.a myTerm/mt_lib.a console/cons_lib.a

console/cons_lib.a: console/print*.o
	ar rcs console/cons_lib.a console/print*.o

console/print*.o: console/print*.c
	gcc -g -c -I include/ console/print*.c mySimpleComputer/sc_lib.a myTerm/mt_lib.a
	cp *.o console
	rm *.o
	
myTerm/mt_lib.a: myTerm/*.o
	ar rcs myTerm/mt_lib.a myTerm/*.o

mySimpleComputer/sc_lib.a: mySimpleComputer/sc*.o
	ar rcs mySimpleComputer/sc_lib.a mySimpleComputer/sc*.o

myTerm/*.o: myTerm/*.c
	gcc -g -c -I include/ myTerm/*.c
	cp *.o myTerm
	rm *.o

mySimpleComputer/sc*.o: mySimpleComputer/sc*.c
	gcc -g -c -I include/ mySimpleComputer/sc*.c
	cp *.o mySimpleComputer
	rm *.o

.PHONY: clean

clean:
	rm mySimpleComputer/*.o
	rm mySimpleComputer/*.a
	rm myTerm/*.o
	rm myTerm/*.a
	rm console/*.o
	rm console/console

.PHONY: run

run:
	./console/console