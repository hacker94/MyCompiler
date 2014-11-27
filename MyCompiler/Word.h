#pragma once

#include <string>
#include "Token.h"

namespace lexer {

	class Word : public Token {
	public:
						Word(Tag tag, std::string lexeme);
						~Word();
		std::string		lexeme;

	};

}

