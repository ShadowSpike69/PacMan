@echo off
echo Compilare proiect PacMan...

cl /c main.cpp Map.cpp Player.cpp Ghost.cpp GameEngine.cpp InputHandler.cpp CollisionManager.cpp
cl main.obj Map.obj Player.obj Ghost.obj GameEngine.obj InputHandler.obj CollisionManager.obj /FePacMan.exe

echo Compilare finalizată!
