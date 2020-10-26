class Position {
public:
  unsigned char x, y;
  bool directions[4];
  enum { NORTH, SOUTH, EAST, WEST };

  Position(unsigned char x, unsigned char y) {
    this->x = x;
    this->y = y;
    directions[NORTH] = directions[SOUTH] = directions[EAST] = directions[WEST] = false;
  }

  unsigned char getDirectionCount() {

    unsigned char dirs = 0;

    for (int i = 0; i < 4; i++)
      if (directions[i] == true)
        dirs++;

    return dirs;
  }
};
