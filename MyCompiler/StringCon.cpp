#include "StringCon.h"
using namespace lexer;


StringCon::StringCon(std::string value) : Token(STRCON), value(value) {
}


StringCon::~StringCon() {
}
