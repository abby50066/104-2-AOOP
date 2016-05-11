all: main

CC = g++
CFLAG = -Wall -ggdb -std=c++11

main: Complex.o main.o
	$(CC) $(CFLAG) -o main Complex.o main.o

Complex.o: Complex.cpp
	$(CC) $(CFLAG) -c Complex.cpp

main.o: main.cpp
	$(CC) $(CFLAG) -c main.cpp

dep:
	$(CC) $(CFLAG) -M *.c > depend

clean:
	rm -f main *.o

