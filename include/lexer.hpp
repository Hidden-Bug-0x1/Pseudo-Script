#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include "position.hpp"
#include "token.hpp"

class Lexer {
private:
  Position index;           // current index of the lexer
  char cur_char;            // current character being looked at
  std::string text;         // data being lexed
public:
  Lexer(std::string text);  // constructor
  void advance();           // advances the position
  TOKEN next_token();       // gets the next token
  TOKEN make_identifier();  // makes an identifier
  TOKEN make_number();      // makes a number token
};

#endif