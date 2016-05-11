#include "Token.h"

using namespace std;

Token::Token(int t) : tag(t)
{
	
}

Token::~Token()
{
	
}

string Token::toString()
{
	string s;
	s = "Token: " + string(1, (char)tag) + "\t(" + string(1, (char)tag) + ")";
	return s;
}
