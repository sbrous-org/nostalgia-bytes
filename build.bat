@echo off
REM Batch file to build all games for Windows

if not exist bin mkdir bin

echo Building Traffigo (Car Race)...
g++ -Wall -std=c++17 games\car_race\traffigo.cpp -o bin\car_race.exe
echo Building Egatho (Egg Basket)...
g++ -Wall -std=c++17 games\egg_basket\*.cpp -o bin\egg_basket.exe

echo Building Serpente (Snake)...
g++ -Wall -std=c++17 games\serpente\serpente.cpp -o bin\serpente.exe

echo Building Traffigo (Car Race)...
g++ -Wall -std=c++17 games\traffigo\traffigo.cpp -o bin\traffigo.exe

echo Building Egatho (Egg Basket)...
g++ -Wall -std=c++17 games\egatho\egatho.cpp -o bin\egatho.exe

echo Building Broppy (Breakout Clone)...
g++ -Wall -std=c++17 games\broppy\broppy.cpp -o bin\broppy.exe

echo Build complete.
pause
