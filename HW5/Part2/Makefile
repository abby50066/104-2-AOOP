all : main

CC = g++
CFLAG = -Wall -ggdb -std=c++11

main: main.o Trace.o
	$(CC) $(CFLAG) -o main main.o Trace.o

Trace.o: Trace.cpp
	$(CC) $(CFLAG) -c Trace.cpp

main.o: main.cpp
	$(CC) $(CFLAG) -D__TRACE__ -c main.cpp

dep:
	$(CC) $(CFLAG) -M *.cpp > depend

clean:
	rm -f main *.o depend
