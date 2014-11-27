#pragma once
#include "Token.h"

namespace lexer {

	class CharCon : public Token {
	public:
					CharCon(char value);
					~CharCon();
		char		value;

	};

}

