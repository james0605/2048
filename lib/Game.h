#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono> 
#include <thread> 
#include <windows.h>

class Game{
public:
    Game();
    Grid grid;
    bool isRunning;
    void run();
    void exit();
    void processInput();
    void update();
    void render();

};

#endif