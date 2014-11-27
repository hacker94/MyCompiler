#pragma once

namespace lexer {

	enum Tag {
		IDEN,
		INTCON,
		CHARCON,
		STRCON,
		CONSTTK,
		INTTK,
		CHARTK,
		VOIDTK,
		VARTK,
		MAINTK,
		IFTK,
		THENTK,
		ELSETK,
		WHILETK,
		SWITCHTK,
		CASETK,
		SCANFTK,
		PRINTFTK,
		RETURNTK,
		PLUS,
		MINU,
		MULT,
		DIV,
		LSS,
		LEQ,
		GER,
		GEQ,
		EQL,
		NEQ,
		ASSIGN,
		SEMICN,
		COMMA,
		LPARENT,
		RPARENT,
		LBRACK,
		RBRACK,
		LBRACE,
		RBRACE
	};

	class Token {
	public:
					Token(Tag tag);
					~Token();
		Tag			tag;

	};
}

