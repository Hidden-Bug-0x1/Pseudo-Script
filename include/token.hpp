#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "position.hpp"
#include <string>

enum class TOKEN {
  IDENTIFIER, // a variable/class/function name
  FUNCTION,   // func:
  CLASS,      // class:
  NUMBER,     // any combination of digits
  L_PAREN,    // (
  R_PAREN,    // )
  L_CURLY,    // {  
  R_CURLY,    // }
  L_BRACKET,  // [
  R_BRACKET,  // ]
  ERROR,      // Error parsing input
  EORF,       // no more text
};

class Token {
private:
  TOKEN token;
  std::string value;
  Position position;
public:
  Token();  
  Token(std::string val, TOKEN tok, Position pos);
  bool operator!= (const TOKEN& t);
  Token* copy();
  std::string to_string(); // for testing
};

#endif