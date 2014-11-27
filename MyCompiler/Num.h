#pragma once

#include "Token.h"

namespace lexer {

	class Num : public Token {
	public:
					Num(int value);
					~Num();
		int			value;

	};

}

