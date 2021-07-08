#ifndef POSITION_HPP
#define POSITION_HPP

#include <stdlib.h>

class Position {
private:
  ushort col;
  ushort line;
public:
  size_t index; // accumulated position
  Position(ushort col_, ushort line_, size_t ind=-1);
  void advance(); // increment col
  void newline(); // increment line and reset col
  Position* copy(); // create a new Position with the same values
  Position(); // compiler throwing fit...
};

#endif