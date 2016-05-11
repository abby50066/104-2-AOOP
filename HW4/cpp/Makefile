all : main

CC = g++
CFLAG = -Wall -ggdb -std=c++11

main: Main.o Lexer.o Real.o Num.o Type.o Word.o Token.o
	$(CC) $(CFLAG) -o main Main.o Lexer.o Real.o Num.o Type.o Word.o Token.o

Token.o : Token.cpp
	$(CC) $(CFLAG) -c Token.cpp

Word.o : Word.cpp
	$(CC) $(CFLAG) -c Word.cpp

Type.o : Type.cpp
	$(CC) $(CFLAG) -c Type.cpp

Num.o : Num.cpp
	$(CC) $(CFLAG) -c Num.cpp

Real.o : Real.cpp
	$(CC) $(CFLAG) -c Real.cpp

Lexer.o: Lexer.cpp
	$(CC) $(CFLAG) -c Lexer.cpp

Main.o: Main.cpp
	$(CC) $(CFLAG) -c Main.cpp

dep:
	$(CC) $(CFLAG) -M *.c > depend

clean:
	rm -f main *.o
