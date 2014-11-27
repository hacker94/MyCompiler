#include "CharCon.h"
using namespace lexer;


CharCon::CharCon(char value) : Token(CHARCON), value(value) {
}


CharCon::~CharCon() {
}
