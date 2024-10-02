#ifndef GRID_H
#define GRID_H

#include <vector>
#include <cstdlib>
#include <ctime>

const int H = 4;
const int W = 4;

class Grid{
public:

    Grid();
    int emptyCnt;
    std::vector<std::vector<int>> grid;
    void generateNewTile();

    bool isFull();
    bool canCombine();


    void shiftLeft();
    void shiftRight();
    void shiftUp();
    void shiftDown();

private:
    
};

#endif