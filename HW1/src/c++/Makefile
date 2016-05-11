all: test1 test2

CC = g++
CFLAG = -Wall -ggdb

test1: stack.o main.o
	$(CC) $(CFLAG) -o test1 stack.o main.o

test2: stack.o main2.o
	$(CC) $(CFLAG) -o test2 stack.o main2.o

stack.o: stack.c
	$(CC) $(CFLAG) -c stack.c

main.o: main.c
	$(CC) $(CFLAG) -c main.c

main2.o: main2.c
	$(CC) $(CFLAG) -c main2.c

dep:
	$(CC) $(CFLAG) -M *.c > depend

clean:
	rm -f test1 test2 *.o

