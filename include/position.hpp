#ifndef POSITION_HPP
#define POSITION_HPP

#define ushort unsigned short

class Position {
private:
  ushort col;
  ushort line;
public:
  Position(ushort col_, ushort line_);
  void advance();
  Position* copy();
};

#endif