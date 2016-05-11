#include "Word.h"

using namespace std;

Word::Word(string s, int tag) : Token(tag)
{
	lexeme = s;
}

string Word::toString()
{
	string s;
	s = "Token: " + lexeme + "\t(";

	switch (tag) {
		case Tag::AND:
			s += "AND)";
			return s;
		case Tag::BASIC:
			s += "BASIC)";
			return s;
		case Tag::BREAK:
			s += "BREAK)";
			return s;
		case Tag::DO:
			s += "DO)";
			return s;
		case Tag::ELSE:
			s += "ELSE)";
			return s;
		case Tag::EQ:
			s += "EQ)";
			return s;
		case Tag::FALSE:
			s += "FALSE)";
			return s;
		case Tag::GE:
			s += "GE)";
			return s;
		case Tag::ID:
			s += "ID)";
			return s;
		case Tag::IF:
			s += "IF)";
			return s;
		case Tag::INDEX:
			s += "INDEX)";
			return s;
		case Tag::LE:
			s += "LE)";
			return s;
		case Tag::MINUS:
			s += "MINUS)";
			return s;
		case Tag::NE:
			s += "NE)";
			return s;
		case Tag::NUM:
			s += "NUM)";
			return s;
		case Tag::OR:
			s += "OR)";
			return s;
		case Tag::REAL:
			s += "REAL)";
			return s;
		case Tag::TEMP:
			s += "TEMP)";
			return s;
		case Tag::TRUE:
			s += "TRUE)";
			return s;
		case Tag::WHILE:
			s += "WHILE)";
			return s;
		default:
			s += " )";
			return s;
	}
}

const Word Word::And = Word("&&", Tag::AND);
const Word Word::Or = Word("||", Tag::OR);
const Word Word::Eq = Word("==", Tag::EQ);
const Word Word::Ne = Word("!=", Tag::NE);
const Word Word::Le = Word("<=", Tag::LE);
const Word Word::Ge = Word(">=", Tag::GE);
const Word Word::Minus = Word("minus", Tag::MINUS);
const Word Word::True = Word("true", Tag::TRUE);
const Word Word::False = Word("false", Tag::FALSE);
const Word Word::Temp = Word("t", Tag::TEMP);
