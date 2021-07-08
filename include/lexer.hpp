#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <vector>
#include <iostream> // for testing stuff...
#include "position.hpp"
#include "token.hpp"

class Lexer {
private:
  Position index;           // current index of the lexer
  char cur_char;            // current character being looked at
  std::string text;         // data being lexed
  void skip_whitespace();   // skip whitespace
public:
  Lexer(std::string text);  // constructor
  bool advance();           // advances the position
  Token next_token();       // gets the next token
  Token make_identifier();  // makes an identifier
  Token make_number();      // makes a number token
  std::vector<Token> lex(); // lexes the input
};

#endif