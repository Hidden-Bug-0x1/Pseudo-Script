#include "../include/token.hpp"

Token::Token()
{
  value = "";
  token = TOKEN::NUMBER; // anything but TOKEN::EORF
  position = *new Position();
}

Token::Token(std::string val, TOKEN tok, Position pos)
{
  value = val;
  token = tok;
  position = pos;
}

bool Token::operator!= (const TOKEN& t)
{
  return token != t;
}

std::string Token::to_string()
{
  std::string output = "";

  output += '[';
  for (char c : value)
  {
    output += c;
  }
  output += ',';
  std::string tok;
  switch(token)
  {
    case TOKEN::IDENTIFIER:
      tok = " IDENTIFIER]";
      break;
    case TOKEN::FUNCTION:
      tok = " FUNCTION]";
      break;
    case TOKEN::CLASS:
      tok = " CLASS]";
      break;
    case TOKEN::NUMBER:
      tok = " NUMBER]";
      break;
    case TOKEN::L_PAREN:
      tok = " L_PAREN]";
      break;
    case TOKEN::R_PAREN:
      tok = " R_PAREN]";
      break;
    case TOKEN::L_CURLY:
      tok = " L_CURLY]";
      break;
    case TOKEN::R_CURLY:
      tok = " R_CURLY]";
      break;
    case TOKEN::L_BRACKET:
      tok = " L_BRACKET]";
      break;
    case TOKEN::R_BRACKET:
      tok = " R_BRACKET]";
      break;
    case TOKEN::ERROR:
      tok = " ERROR]";
      break;
    case TOKEN::EORF:
      tok = " EORF]";
      break;
  }
  for (char c : tok)
  {
    output += c;
  }

  return output;
}