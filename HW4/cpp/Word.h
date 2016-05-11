#ifndef __WORD_H__
#define __WORD_H__

#include <string>
#include "Tag.h"
#include "Token.h"

using namespace std;

class Word : public Token {

public:
	string lexeme = "";
	Word(string s, int tag);
	string toString();
	static const Word And;
	static const Word Or;
	static const Word Eq;
	static const Word Ne;
	static const Word Le;
	static const Word Ge;
	static const Word Minus;
	static const Word True;
	static const Word False;
	static const Word Temp;
};

#endif
