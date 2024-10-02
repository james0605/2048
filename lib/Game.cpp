#include "../lib/Game.h"

#define VK_LEFT 75
#define VK_UP 72
#define VK_RIGHT 77
#define VK_DOWN 80

void setCursorPosition(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void hideCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}



Game::Game(){
    isRunning = true;
}

void Game::run(){

    while (isRunning){
        update();
        processInput();
        
    }
}

void Game::exit(){
    isRunning = false;
    std::cout << "Press any key to exit." << std::endl;
    _getch();
}

void Game::processInput(){
    char key = _getch();
    if (key == 'e' || key == 'E') exit();
    else if (key == -32){
        key = _getch();
        switch (key){
            case VK_UP:
                grid.shiftUp();
                break;
            case VK_DOWN:
                grid.shiftDown();
                break;
            case VK_LEFT:
                grid.shiftLeft();
                break;
            case VK_RIGHT:
                grid.shiftRight();
                break;
            default:
                break;
        }
    }
}
void Game::update(){
    if (grid.isFull() && !grid.canCombine()){
        std::cout << "Game Over!!" << std::endl;
        exit();
    }
    else grid.generateNewTile();
    render();
}

void Game::render(){
    // clear terminal
    system("cls");
    // hideCursor();
    // setCursorPosition(0, 0);

    // render
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            std::cout << grid.grid[i][j] << '\t';
        }
        std::cout << std::endl;
    }
    
    std::cout << "Empty Count : " <<  grid.emptyCnt << std::endl;
}
