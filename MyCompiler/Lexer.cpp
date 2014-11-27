#include "Lexer.h"
using namespace lexer;

Lexer::Lexer(string text) {
	this->text = text;

	reserve(new Word(CONSTTK, "const"));
	reserve(new Word(INTTK, "int"));
	reserve(new Word(CHARTK, "char"));
	reserve(new Word(VOIDTK, "void"));
	reserve(new Word(VARTK, "var"));
	reserve(new Word(MAINTK, "main"));
	reserve(new Word(IFTK, "if"));
	reserve(new Word(THENTK, "then"));
	reserve(new Word(ELSETK, "else"));
	reserve(new Word(WHILETK, "while"));
	reserve(new Word(SWITCHTK, "switch"));
	reserve(new Word(CASETK, "case"));
	reserve(new Word(SCANFTK, "scanf"));
	reserve(new Word(PRINTFTK, "printf"));
	reserve(new Word(RETURNTK, "return"));
	reserve(new Word(PLUS, "+"));
	reserve(new Word(MINU, "-"));
	reserve(new Word(MULT, "*"));
	reserve(new Word(DIV, "/"));
	reserve(new Word(LSS, "<"));
	reserve(new Word(LEQ, "<="));
	reserve(new Word(GER, ">"));
	reserve(new Word(GEQ, ">="));
	reserve(new Word(EQL, "=="));
	reserve(new Word(NEQ, "!="));
	reserve(new Word(ASSIGN, "="));
	reserve(new Word(SEMICN, ";"));
	reserve(new Word(COMMA, ","));
	reserve(new Word(LPARENT, "("));
	reserve(new Word(RPARENT, ")"));
	reserve(new Word(LBRACK, "["));
	reserve(new Word(RBRACK, "]"));
	reserve(new Word(LBRACE, "{"));
	reserve(new Word(RBRACE, "}"));
}

Lexer::~Lexer() {
}

void Lexer::reserve(Word* t) {
	words[t->lexeme] = t;
}

Token* Lexer::scan() {
	string simpleReserved = "+-*/()[]{};,";

	for (; textIdx < text.length(); textIdx++) {
		peek = text[textIdx];
		// skip blank char
		if (peek == ' ' || peek == '\t') {
			continue;
		} else if (peek == '\n') {
			line++;
			continue;
		}

		if (isdigit(peek)) {
			// intcon
			int value = 0;
			do {
				value = value * 10 + peek - '0';
				peek = text[++textIdx];
			} while (isdigit(peek));
			return new Num(value);

		} else if (isalpha(peek) || peek == '_') {
			// word
			string lexeme = "";
			do {
				lexeme += peek;
				peek = text[++textIdx];
			} while (isalnum(peek) || peek == '_');
			// find word in table
			if (words.count(lexeme)) {
				return words[lexeme];
			} else {
				return new Word(IDEN, lexeme);
			}

		} else if (peek == '\'') {
			// CharCon
			peek = text[++textIdx];
			char value;
			if (peek != '\'') {
				value = peek;
			} else {
				// todo: error msg
			}
			peek = text[++textIdx];
			if (peek != '\'') {
				// todo: error msg
			}
			peek = text[++textIdx];
			return new CharCon(value);

		} else if (peek == '\"') {
			//StringCon
			peek = text[++textIdx];
			string value = "";
			while (peek != '\"') {
				value += peek;
				peek = text[++textIdx];
			}
			peek = text[++textIdx];
			return new StringCon(value);

		} else if (peek == '<') {
			// < and <=
			peek = text[++textIdx];
			if (peek != '=') {
				return words["<"];
			} else {
				peek = text[++textIdx];
				return words["<="];
			}

		} else if (peek == '>') {
			// > and >= 
			peek = text[++textIdx];
			if (peek != '=') {
				return words[">"];
			} else {
				peek = text[++textIdx];
				return words[">="];
			}

		} else if (peek == '=') {
			// = and ==
			peek = text[++textIdx];
			if (peek != '=') {
				return words["="];
			} else {
				peek = text[++textIdx];
				return words["=="];
			}

		} else if (peek == '!') {
			// !=
			peek = text[++textIdx];
			if (peek != '=') {
				// todo: error msg
			} else {
				peek = text[++textIdx];
				return words["!="];
			}

		} else if (simpleReserved.find(peek) != simpleReserved.npos) {
			// +-*/()[]{};,
			string t = " ";
			t[0] = peek;
			peek = text[++textIdx];
			return words[t];
		}
	}
	return nullptr;

}