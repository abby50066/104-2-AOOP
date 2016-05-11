#ifndef __REAL_H__
#define __REAL_H__

#include <string>
#include "Tag.h"
#include "Token.h"

class Real : public Token {

public:
	const float value;
	Real(float v) ;
	string toString();
};

#endif
