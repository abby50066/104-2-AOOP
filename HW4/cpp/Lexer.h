#ifndef __LEXER_H__
#define __LEXER_H__

#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>
#include "Word.h"
#include "Tag.h"
#include "Type.h"
#include "Token.h"
#include "Num.h"
#include "Real.h"

class Lexer {
private:
	char peek;
	unordered_map<string, Word> words;
	void reserve(Word w);
	void readch();
	bool readch(char c) throw(string);

public: 
	static int line;
	Lexer();
	Token *scan() throw(string);
};

#endif
