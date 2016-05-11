#include "Type.h"

using namespace std;

Type::Type(string s, int tag, int w) : Word(s, tag)
{
	width = w;
}

bool Type::numeric(Type p)
{
	if (p.lexeme == Type::Char.lexeme || p.lexeme == Type::Int.lexeme || p.lexeme == Type::Float.lexeme)
		return true;
	return false;
}

Type Type::max( Type p1,  Type p2)
{
	if (!numeric(p1) || !numeric(p2))
		return TypeNULL;
	else if (p1.lexeme == Type::Float.lexeme || p2.lexeme == Type::Float.lexeme)
		return Type::Float;
	else if (p1.lexeme == Type::Int.lexeme || p2.lexeme == Type::Int.lexeme)
		return Type::Int;
	return Type::Char;
}

const Type Type::Int = Type("int", Tag::BASIC, 4);
const Type Type::Float = Type("float", Tag::BASIC, 8);
const Type Type::Char = Type("char", Tag::BASIC, 1);
const Type Type::Bool = Type("bool", Tag::BASIC, 1);
