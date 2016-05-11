#include <iostream>

#include "Tag.h"
#include "Token.h"
#include "Word.h"
#include "Type.h"
#include "Num.h"
#include "Real.h"
#include "Lexer.h"

using namespace std;

int main(int argc, char** argv) throw(string)
{
	Lexer lexer = Lexer();
	try {
		while (true) {
			Token *t = lexer.scan();
			cout << t->toString() << endl;
			delete t;
		}
	} catch (string e) {
		cout << e << endl;
	}
	
	return 0;
}
