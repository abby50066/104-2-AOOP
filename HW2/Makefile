all: mytar

CC = g++
CFLAG = -Wall -ggdb -std=c++11

mytar: mytar.o myhw2.o main.o
	$(CC) $(CFLAG) -o mytar mytar.o myhw2.o main.o

mytar.o: mytar.cpp
	$(CC) $(CFLAG) -c mytar.cpp

myhw2.o: myhw2.cpp
	$(CC) $(CFLAG) -c myhw2.cpp

main.o: main.cpp
	$(CC) $(CFLAG) -c main.cpp

dep:
	$(CC) $(CFLAG) -M *.c > depend

clean:
	rm -f mytar *.o

