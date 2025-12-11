@echo off
echo === Compilare module principale ===
cl /EHsc /c main.cpp /I libs\Player /I libs\Ghost /I libs\Map /I libs\InputHandler /I libs\CollisionManager /I libs\GameEngine /I libs\Common
cl /EHsc /c libs\Player\Player.cpp /I libs\Common
cl /EHsc /c libs\Ghost\Ghost.cpp /I libs\Common
cl /EHsc /c libs\Map\Map.cpp /I libs\Common
cl /EHsc /c libs\InputHandler\InputHandler.cpp
cl /EHsc /c libs\CollisionManager\CollisionManager.cpp
cl /EHsc /c libs\GameEngine\GameEngine.cpp




echo === Legare cu biblioteci statice ===
cl main.obj GameEngine.obj Player.lib Ghost.lib Map.lib InputHandler.lib CollisionManager.lib /FePacMan.exe

echo === Build completat ===
pause
