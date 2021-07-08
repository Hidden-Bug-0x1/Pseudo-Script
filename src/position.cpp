#include "../include/position.hpp"

// constructor
Position::Position(ushort col_, ushort line_)
: col(col_), line(line_)
{

}
// increment col
void Position::advance()
{
  col++;
} 

// increment line and reset col
void Position::newline()
{
  line++;
  col = 0;
} 

// create a new Position with the same values
Position* Position::copy()
{
  return new Position(col, line);
}