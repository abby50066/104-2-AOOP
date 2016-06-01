all : main

CC = g++
CFLAG = -Wall -ggdb -std=c++11

main: main.o
	$(CC) $(CFLAG) -o main main.o

main.o: main.cpp
	$(CC) $(CFLAG) -c main.cpp

dep:
	$(CC) $(CFLAG) -M *.c > depend

clean:
	rm -f main *.o
