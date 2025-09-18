#pragma once

class Ghost {
public:
   void move();
   int getX() const;
   int getY() const;
   void resetPosition();
private:
   int x,y;
   bool isScared;
};
