#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>
#include "Tag.h"

using namespace std;

class Token {
public:
	const int tag;
	Token(int t);
	virtual ~Token();
	virtual string toString();
};

#endif
