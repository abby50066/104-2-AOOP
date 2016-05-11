#include "Lexer.h"

void Lexer::reserve(Word w)
{
	words.insert({w.lexeme, w});
}
	
void Lexer::readch()
{
	int i = cin.get();
	if (i != -1)
		peek = (char) i;
	else
		throw string("End of file reached");
}

bool Lexer::readch(char c) throw(string)
{
	readch();
	if (peek != c)
		return false;
	peek = ' ';
	return true;
}

Lexer::Lexer()
{
	peek = ' ';
	reserve(Word("if", Tag::IF) );
	reserve(Word("else", Tag::ELSE) );
	reserve(Word("while", Tag::WHILE) );
	reserve(Word("do", Tag::DO) );
	reserve(Word("break", Tag::BREAK) );
	reserve(Word::True);
	reserve(Word::False);
	reserve(Type::Int);
	reserve(Type::Char);
	reserve(Type::Bool);
	reserve(Type::Float);
}
Token *Lexer::scan() throw(string)
{
	for ( ; ; readch()) {
		if (peek == ' ' || peek == '\t' || peek == '\r')
			continue;
		else if (peek == '\n')
			line = line + 1;
		else
			break;
	}
	switch (peek) {
	case '&':
		if (readch('&'))
			return new Word(Word::And.lexeme, Word::And.tag);
		else
			return new Token('&');
	case '|':
		if (readch('|'))
			return new Word(Word::Or.lexeme, Word::Or.tag);
		else
			return new Token('|');
	case '=':
		if (readch('='))
			return new Word(Word::Eq.lexeme, Word::Eq.tag);
		else
			return new Token('=');
	case '!':
		if (readch('='))
			return new Word(Word::Ne.lexeme, Word::Ne.tag);
		else
			return new Token('!');
	case '<':
		if (readch('='))
			return new Word(Word::Le.lexeme, Word::Le.tag);
		else
			return new Token('<');
	case '>':
		if (readch('='))
			return new Word(Word::Ge.lexeme, Word::Ge.tag);
		else
			return new Token('>');
	}

	if (isdigit(peek)) {
		int v = 0;
		do {
			v = 10 * v + (peek - '0');
			readch();
		} while (isdigit(peek));

		if (peek != '.')
			return new Num(v);

		float x = v;
		float d = 10;
		for (;;) {
			readch();
			if (!isdigit(peek))
				break;
			x = x + (peek - '0');
			d = d * 10;
		}
		return new Real(x);
	}

	if (isalpha(peek)){
		string b = string("");
		do {
			b += peek;
			readch();
		} while (isalnum(peek));
		string s = b;
		unordered_map<string, Word>::const_iterator got = words.find(s);
		if (got != words.end()){
			Word *w = new Word(got->second.lexeme, got->second.tag);
			return w;
		}
		Word *w = new Word(s, Tag::ID);
		words.insert({s, *w});
		return w;
	}

	Token *tok = new Token(peek);
	peek = ' ';
	return tok;
}

int Lexer::line = 1;
