@echo off
REM Batch file to build all games for Windows

if not exist bin mkdir bin

echo Building Serpente (Snake)...
g++ -Wall -std=c++17 games\snake\serpente.cpp -o bin\snake.exe

echo Building Traffigo (Car Race)...
g++ -Wall -std=c++17 games\car_race\traffigo.cpp -o bin\car_race.exe

echo Building Egatho (Egg Basket)...
g++ -Wall -std=c++17 games\egg_basket\*.cpp -o bin\egg_basket.exe

echo Build complete.
pause
