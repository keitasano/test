default: main

testda: linkedList.o testLinkedList.o
	gcc -g -Wall -std=c99 -o testda linkedList.o testLinkedList.o

main: linkedList.o linkedListResourceTest.o
	gcc -g -Wall -std=c99 -o main linkedList.o linkedListResourceTest.o

linkedList.o: linkedList.c linkedList.h
	gcc -Wall -std=c99 -c linkedList.c

prog: linkedList.o
	gcc -Wall -std=c99 -o prog linkedList.o linkedListMain.c

clean:
	rm linkedList.o

cleanall: clean
	rm prog
