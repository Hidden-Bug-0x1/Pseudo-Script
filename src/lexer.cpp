#include "../include/lexer.hpp"

// constructor
Lexer::Lexer(std::string text)
{
  this->text = text;
  index = *new Position(-1, 0);
  cur_char = text[index.index];
}

// skip whitespace
void Lexer::skip_whitespace()
{
  switch (cur_char)
  {
    case '\n':
      index.newline();
      break;
  }
}

// advances the position
bool Lexer::advance()
{
  if (index.index+1 < text.size())
  {
    index.advance();
    cur_char = text[index.index];

    return true; // was able to advance
  }

  return false; // wasn't able to advance
}

// gets the next token
Token Lexer::next_token()
{
  while (advance())
  {
    if (isalpha(cur_char))
    {
      return make_identifier();
    } 
    else if (isdigit(cur_char))
    {
      return make_number();
    } 
    else
    {
      switch(cur_char)
      {
        case '(':
          return *new Token(std::string(&cur_char), TOKEN::L_PAREN, *index.copy());
        case ')':
          return *new Token(std::string(&cur_char), TOKEN::R_PAREN, *index.copy());
        case '{':
          return *new Token(std::string(&cur_char), TOKEN::L_CURLY, *index.copy());
        case '}':
          return *new Token(std::string(&cur_char), TOKEN::R_CURLY, *index.copy());
        case '[':
          return *new Token(std::string(&cur_char), TOKEN::L_BRACKET, *index.copy());
        case ']': 
          return *new Token(std::string(&cur_char), TOKEN::R_BRACKET, *index.copy());
        default:
          return *new Token(std::string(&cur_char), TOKEN::ERROR, *index.copy());
      }
    }
  }
  return *new Token("", TOKEN::EORF, *index.copy());
}

// makes an identifier
Token Lexer::make_identifier() 
{
  std::string identifier = "";

  Position p = *index.copy();

  while(isalnum(cur_char))
  {
    identifier += cur_char;
    if (!advance()) break;
  }

  skip_whitespace();

  return *new Token(identifier, TOKEN::IDENTIFIER, p);
}

// makes a number token
Token Lexer::make_number()
{
  std::string number = "";

  Position p = *index.copy();

  bool bad = false;

  while (isalnum(cur_char))
  {
    number += cur_char;
    if (isalpha(cur_char)) bad = true;
    if (!advance()) break;
  }

  if (bad) 
  {
    return *new Token(number, TOKEN::ERROR, p);
  }

  return *new Token(number, TOKEN::NUMBER, p);
}

// lexes the input
std::vector<Token> Lexer::lex()
{
  std::vector<Token> tokens;
  Token token;
  while( (token = next_token()) != TOKEN::EORF )
  {
    tokens.push_back(token);
  }
  return tokens;
}