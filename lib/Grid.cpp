#include "../lib/Grid.h"

Grid::Grid(): grid(4, std::vector<int>(4, 0)){
    emptyCnt = 16;
    generateNewTile();
    generateNewTile();
}
void Grid::generateNewTile() {
    if (emptyCnt == 0) return;
    int r = rand() % emptyCnt;
    int count = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 0) {
                if (count == r) {
                    grid[i][j] = (rand() % 2 + 1) * 2;
                    emptyCnt--;
                    return;
                }
                count++;
            }
        }
    }
}



bool Grid::isFull(){
    return (emptyCnt == 0);
}

bool Grid::canCombine(){
    for (int i = 0; i < H - 1; i++){
        for (int j = 0; j < W - 1; j++){
            if (grid[i][j] == grid[i][j + 1] || grid[i][j] == grid[i + 1][j]) return true;
        }
    }
    return false;
}

void Grid::shiftLeft() {
    for (int i = 0; i < H; i++) {
        int lastNonZero = -1;
        int insertPos = 0;
        for (int j = 0; j < W; j++) {
            if (grid[i][j] != 0) {
                if (lastNonZero != -1 && grid[i][j] == grid[i][lastNonZero]) {
                    grid[i][insertPos - 1] *= 2;
                    grid[i][j] = 0;
                    lastNonZero = -1;
                    emptyCnt++;
                }
                else {
                    lastNonZero = j;
                    if (insertPos != j) {
                        grid[i][insertPos] = grid[i][j];
                        grid[i][j] = 0;
                    }
                    insertPos++;
                }
            }
        }
    }
}

void Grid::shiftRight(){
        for (int i = 0; i < H; i++) {
        int lastNonZero = -1;
        int insertPos = W - 1;
        for (int j = W - 1; j >= 0; j--) {
            if (grid[i][j] != 0) {
                if (lastNonZero != -1 && grid[i][j] == grid[i][lastNonZero]) {
                    grid[i][insertPos + 1] *= 2;
                    grid[i][j] = 0;
                    lastNonZero = -1;
                    emptyCnt++;
                }
                else {
                    lastNonZero = j;
                    if (insertPos != j) {
                        grid[i][insertPos] = grid[i][j];
                        grid[i][j] = 0;
                    }
                    insertPos--;
                }
            }
        }
    }
}
void Grid::shiftUp() {
    for (int j = 0; j < W; j++) {
        int lastNonZero = -1; 
        int insertPos = 0;

        for (int i = 0; i < H; i++) {
            if (grid[i][j] != 0) {
                if (lastNonZero != -1 && grid[i][j] == grid[lastNonZero][j]) {
                    grid[insertPos - 1][j] *= 2;
                    grid[i][j] = 0;
                    lastNonZero = -1;
                    emptyCnt++;
                } 
                else {
                    lastNonZero = i;
                    if (insertPos != i) {
                        grid[insertPos][j] = grid[i][j];
                        grid[i][j] = 0;
                    }
                    insertPos++;
                }
            }
        }
    }
}

void Grid::shiftDown() {
    for (int j = 0; j < W; j++) {
        int lastNonZero = -1;
        int insertPos = H - 1;

        for (int i = H - 1; i >= 0; i--) { 
            if (grid[i][j] != 0) {
                if (lastNonZero != -1 && grid[i][j] == grid[lastNonZero][j]) {
                    grid[insertPos + 1][j] *= 2; 
                    grid[i][j] = 0; 
                    lastNonZero = -1; 
                    emptyCnt++;
                } 
                else {
                    lastNonZero = i;
                    if (insertPos != i) {
                        grid[insertPos][j] = grid[i][j]; 
                        grid[i][j] = 0; 
                    }
                    insertPos--; 
                }
            }
        }
    }
}

