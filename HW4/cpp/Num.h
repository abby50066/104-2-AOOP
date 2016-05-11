#ifndef __NUM_H__
#define __NUM_H__

#include <string>
#include "Tag.h"
#include "Token.h"

class Num : public Token {
public:
	const int value;
	Num(int v) ;
	string toString();
};

#endif
