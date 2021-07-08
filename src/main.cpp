#include <iostream>
#include <string>

#include "../include/lexer.hpp"

int main(int argc, char* argv[])
{
  std::string text = "read\nme\nnow!";

  Lexer l = *new Lexer(text);

  while(l.advance()){}

  std::cout << "Compilation Success" << std::endl; 

  return EXIT_SUCCESS;
}