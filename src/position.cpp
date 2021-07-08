#include "../include/position.hpp"

// constructor
Position::Position(ushort col_, ushort line_, size_t ind)
: col(col_), line(line_), index(ind)
{

}

// compiler throwing fit...
Position::Position()
{} 

// increment col
void Position::advance()
{
  col++;
  index++;
} 

// increment line and reset col
void Position::newline()
{
  line++;
  index++;
  col = -1;
} 

// create a new Position with the same values
Position* Position::copy()
{
  return new Position(col, line, index);
}