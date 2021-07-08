#include "../include/lexer.hpp"

// constructor
Lexer::Lexer(std::string text)
{
  this->text = text;
  index = *new Position(-1, 0);
  cur_char = text[index.index];
}

// advances the position
bool Lexer::advance()
{
  if (index.index+1 < text.size())
  {
    index.advance();
    cur_char = text[index.index];

    switch (cur_char)
    {
      case ' ':
        advance();
        break;
      case '\n':
        index.newline();
        cur_char = text[index.index];
        break;
      case '\t':
        advance();
        break;
    }

    std::cout << "cur_char = '" << cur_char << "'\n";

    return true; // was able to advance
  }

  return false; // wasn't able to advance
}