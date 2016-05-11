#include "Real.h"

Real::Real(float v) : Token(Tag::REAL), value(v)
{
	
}
string Real::toString()
{
	string s;
	s = "Token: " + to_string(value) + "\t(REAL)";
	return s;
}
