#pragma once

#include <string>
#include <map>
#include <cctype>

#include "Token.h"
#include "Num.h"
#include "Word.h"
#include "CharCon.h"
#include "StringCon.h"

using namespace std;

namespace lexer {

	class Lexer {
	public:
								Lexer(string text);
								~Lexer();
		Token*					scan();
	private:
		string					text;
		int						line = 1;
		int						textIdx = 0;
		char					peek = ' ';
		map<string, Word*>		words;

		void					reserve(Word* t);

	};
}
