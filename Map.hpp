#pragma once
#include <vector>

class Map {
public:
   void load();
   void draw() const;
   bool isWall(int x,int y)const;
   bool isPellet(int x,int y)const;
   void eatPellet(int x, int y);
private:
  std::vector<std::vector<char>> grid;
};
