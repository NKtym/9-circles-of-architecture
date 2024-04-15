all: mySimpleComputer/sc_lib.a myTerm/mt_lib.a myBigChars/bc_lib.a myReadKey/rk_lib.a console/cons_lib.a console/font console/console

test: console/test.o
	gcc console/test.o -o console/test
test.o: console/test.c
	gcc -c console/test.c

console/console: console/console.c mySimpleComputer/*.c myTerm/*.c myBigChars/*.c myReadKey/*.c console/print*.c 
	gcc -g -I include/ -o console/console console/console.c mySimpleComputer/sc*.c mySimpleComputer/usrsighandler.c mySimpleComputer/CU.c mySimpleComputer/IRC.c mySimpleComputer/ALU.c myTerm/mt*.c myBigChars/bc*.c myReadKey/rk*.c console/print*.c

console/font: console/font.c myBigChars/bc*.c
	gcc -g -I include/ -o console/font console/font.c myTerm/mt*.c myBigChars/bc*.c

console/cons_lib.a: console/print*.o
	ar rcs console/cons_lib.a console/print*.o

console/print*.o: console/print*.c
	gcc -g -c -I include/ console/print*.c mySimpleComputer/sc_lib.a myTerm/mt_lib.a myReadKey/rk_lib.a
	cp *.o console
	rm *.o

myReadKey/rk_lib.a: myReadKey/*.o
	ar rcs myReadKey/rk_lib.a myReadKey/*.o
	
myBigChars/bc_lib.a: myBigChars/*.o
	ar rcs myBigChars/bc_lib.a myBigChars/*.o

myTerm/mt_lib.a: myTerm/*.o
	ar rcs myTerm/mt_lib.a myTerm/*.o

mySimpleComputer/sc_lib.a: mySimpleComputer/sc*.o
	ar rcs mySimpleComputer/sc_lib.a mySimpleComputer/sc*.o

myReadKey/*.o: myReadKey/rk*.c
	gcc -g -c -I include/ myReadKey/rk*.c
	cp *.o myReadKey
	rm *.o

myBigChars/*.o: myBigChars/bc*.c
	gcc -g -c -I include/ myBigChars/bc*.c
	cp *.o myBigChars
	rm *.o

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
	rm myBigChars/*.o
	rm myBigChars/*.a
	rm console/font
	rm console/console
	rm myReadKey/*.o
	rm myReadKey/*.a
.PHONY: run

run:
	./console/console