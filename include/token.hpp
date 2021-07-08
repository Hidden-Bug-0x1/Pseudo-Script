#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "pseudo.h"

enum class TOKEN {
  IDENTIFIER, // a variable/class/function name
  FUNCTION,   // func:
  CLASS,      // class:
  L_PAREN,    // (
  R_PAREN,    // )
  L_CURLY,    // {  
  R_CURLY,    // }
  L_BRACKET,  // [
  R_BRACKET   // ]
};

class Token {
private:
  TOKEN token;
  std::string value;
  Position position;
public:
  Token(std::string val, TOKEN tok, Position pos);
};

#endif