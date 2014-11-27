#include "Word.h"
using namespace lexer;


Word::Word(Tag tag, std::string lexeme) : Token(tag), lexeme(lexeme) {
}


Word::~Word() {
}
