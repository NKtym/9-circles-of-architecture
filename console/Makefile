all: test

test: test.o
	gcc test.o -o test
test.o: test.c
	gcc -c test.c
clean:
	rm -rf *.o test