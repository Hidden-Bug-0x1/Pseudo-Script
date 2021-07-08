#include "../include/token.hpp"

Token::Token(std::string val, TOKEN tok, Position pos)
{
  value = val;
  token = tok;
  position = pos;
}