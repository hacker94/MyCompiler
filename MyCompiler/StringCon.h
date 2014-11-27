#pragma once

#include <string>
#include "Token.h"

namespace lexer {

	class StringCon : public Token {
	public:
						StringCon(std::string value);
						~StringCon();
		std::string		value;

	};

}

