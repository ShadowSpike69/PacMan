#pragma once
class Player{
public:
   void move(char direction);
   int getX() const;
   int getY() const;
   void resetPosition();
private:
   int x,y;
   int lives;
};
