#include "Num.h"

Num::Num(int v) : Token(Tag::NUM), value(v)
{
	
}
string Num::toString()
{
	string s;
	s = "Token: " + to_string(value) + "\t(NUM)";
	return s;
}
