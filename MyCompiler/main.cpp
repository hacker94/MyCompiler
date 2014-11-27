#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Lexer.h"
using namespace std;
using namespace lexer;

int main() {
	string fname;
	cout << "Please input file name." << endl;
	//cin >> fname;
	fname = "C:/Users/SyW/Documents/GitHub/MyCompiler/Debug/1.txt";

	ifstream fin(fname);
	stringstream ss;
	ss << fin.rdbuf();

	ofstream fout("12061163_token.txt");

	Lexer* lexer = new Lexer(ss.str());
	Token* tk = lexer->scan();
	int i = 1;
	while (tk != nullptr) {
		fout << i << ' ';
		switch (tk->tag) {
		case IDEN:
			fout << "IDEN " << static_cast<Word*>(tk)->lexeme;
			break;
		case INTCON:
			fout << "INTCON " << static_cast<Num*>(tk)->value;
			break;
		case CHARCON:
			fout << "CHARCON " << static_cast<CharCon*>(tk)->value;
			break;
		case STRCON:
			fout << "STRCON " << static_cast<StringCon*>(tk)->value;
			break;
		case CONSTTK:
			fout << "CONSTTK " << static_cast<Word*>(tk)->lexeme;
			break;
		case INTTK:
			fout << "INTTK " << static_cast<Word*>(tk)->lexeme;
			break;
		case CHARTK:
			fout << "CHARTK " << static_cast<Word*>(tk)->lexeme;
			break;
		case VOIDTK:
			fout << "VOIDTK " << static_cast<Word*>(tk)->lexeme;
			break;
		case VARTK:
			fout << "VARTK " << static_cast<Word*>(tk)->lexeme;
			break;
		case MAINTK:
			fout << "MAINTK " << static_cast<Word*>(tk)->lexeme;
			break;
		case IFTK:
			fout << "IFTK " << static_cast<Word*>(tk)->lexeme;
			break;
		case THENTK:
			fout << "THENTK " << static_cast<Word*>(tk)->lexeme;
			break;
		case ELSETK:
			fout << "ELSETK " << static_cast<Word*>(tk)->lexeme;
			break;
		case WHILETK:
			fout << "WHILETK " << static_cast<Word*>(tk)->lexeme;
			break;
		case SWITCHTK:
			fout << "SWITCHTK " << static_cast<Word*>(tk)->lexeme;
			break;
		case CASETK:
			fout << "CASETK " << static_cast<Word*>(tk)->lexeme;
			break;
		case SCANFTK:
			fout << "SCANFTK " << static_cast<Word*>(tk)->lexeme;
			break;
		case PRINTFTK:
			fout << "PRINTFTK " << static_cast<Word*>(tk)->lexeme;
			break;
		case RETURNTK:
			fout << "RETURNTK " << static_cast<Word*>(tk)->lexeme;
			break;
		case PLUS:
			fout << "PLUS " << static_cast<Word*>(tk)->lexeme;
			break;
		case MINU:
			fout << "MINU " << static_cast<Word*>(tk)->lexeme;
			break;
		case MULT:
			fout << "MULT " << static_cast<Word*>(tk)->lexeme;
			break;
		case DIV:
			fout << "DIV " << static_cast<Word*>(tk)->lexeme;
			break;
		case LSS:
			fout << "LSS " << static_cast<Word*>(tk)->lexeme;
			break;
		case LEQ:
			fout << "LEQ " << static_cast<Word*>(tk)->lexeme;
			break;
		case GER:
			fout << "GER " << static_cast<Word*>(tk)->lexeme;
			break;
		case GEQ:
			fout << "GEQ " << static_cast<Word*>(tk)->lexeme;
			break;
		case EQL:
			fout << "EQL " << static_cast<Word*>(tk)->lexeme;
			break;
		case NEQ:
			fout << "NEQ " << static_cast<Word*>(tk)->lexeme;
			break;
		case ASSIGN:
			fout << "ASSIGN " << static_cast<Word*>(tk)->lexeme;
			break;
		case SEMICN:
			fout << "SEMICN " << static_cast<Word*>(tk)->lexeme;
			break;
		case COMMA:
			fout << "COMMA " << static_cast<Word*>(tk)->lexeme;
			break;
		case LPARENT:
			fout << "LPARENT " << static_cast<Word*>(tk)->lexeme;
			break;
		case RPARENT:
			fout << "RPARENT " << static_cast<Word*>(tk)->lexeme;
			break;
		case LBRACK:
			fout << "LBRACK " << static_cast<Word*>(tk)->lexeme;
			break;
		case RBRACK:
			fout << "RBRACK " << static_cast<Word*>(tk)->lexeme;
			break;
		case LBRACE:
			fout << "LBRACE " << static_cast<Word*>(tk)->lexeme;
			break;
		case RBRACE:
			fout << "RBRACE " << static_cast<Word*>(tk)->lexeme;
			break;
		}
		fout << endl;
		tk = lexer->scan();
		i++;
	}


	fin.close();
	fout.close();

	return 0;
}