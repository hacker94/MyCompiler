#include "Num.h"
using namespace lexer;


Num::Num(int value) : Token(INTCON), value(value) {
}


Num::~Num() {
}
