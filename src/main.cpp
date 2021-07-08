#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "../include/lexer.hpp"

int main(int argc, char* argv[])
{
  std::ifstream inputfs;
  inputfs.open("test.pseudo", std::ios::in);

  std::string text;
  while(true)
  {
    char c = inputfs.get();
    if (c == EOF) break;
    text += c;
  }

  Lexer l = *new Lexer(text);
  std::vector<Token> tokens = l.lex();

  for (Token t : tokens)
  {
    std::cout << "Token: " << t.to_string() << std::endl;
  }

  std::cout << "Compilation Success" << std::endl; 

  return EXIT_SUCCESS;
}