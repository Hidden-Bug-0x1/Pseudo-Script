#ifndef POSITION_HPP
#define POSITION_HPP

#include <stdlib.h>

class Position {
private:
  ushort col;
  ushort line;
public:
  Position(ushort col_, ushort line_);
  void advance(); // increment col
  void newline(); // increment line and reset col
  Position* copy(); // create a new Position with the same values
};

#endif