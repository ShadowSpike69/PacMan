@echo off
echo === Compilare module principale ===
cl /EHsc /c main.cpp
cl /EHsc /c GameEngine.cpp

echo === Legare cu biblioteci statice ===
cl main.obj GameEngine.obj /FePacMan.exe Player.lib Map.lib Ghost.lib InputHandler.lib CollisionManager.lib

echo === Build completat ===
pause
