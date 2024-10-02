#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "lib/Grid.h"

void printGrid(const Grid& grid) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cout << grid.grid[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void testGrid() {
    Grid grid;
    std::cout << "Initial Grid:" << std::endl;
    printGrid(grid);

    std::cout << "Shifting Left:" << std::endl;
    grid.shiftLeft();
    printGrid(grid);

    std::cout << "Generating New Tile:" << std::endl;
    grid.generateNewTile();
    printGrid(grid);

    std::cout << "Shifting Right:" << std::endl;
    grid.shiftRight();
    printGrid(grid);

    std::cout << "Shifting Up:" << std::endl;
    grid.shiftUp();
    printGrid(grid);

    std::cout << "Shifting Down:" << std::endl;
    grid.shiftDown();
    printGrid(grid);
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // 用隨機種子初始化隨機數生成器
    testGrid();
    return 0;
}
