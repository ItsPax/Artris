#include <iostream>

const int WIDTH = 10;
const int HEIGHT = 12;


class IoGrid  {
    char blocks[WIDTH][HEIGHT];
public:
    void printGrid();
    void fillGrid();
};

void IoGrid::printGrid()  {
    for (int i = 0; i  < HEIGHT; ++i)    {
        for (int j = 0; j < WIDTH; ++j)    {
            std::cout << this->blocks[j][i];
            if (j == WIDTH-1)   {
                std::cout << '\n';
            }
        }
    }
}

void IoGrid::fillGrid() {
    for (int i = 0; i  < HEIGHT; ++i)    {
        for (int j = 0; j < WIDTH; ++j)    {
            this->blocks[j][i] = '.';
        }
    }
}

void IoGrid::spawnBlock()   {
    // use some rand function later, hardcode it at some point

int main()  {
    IoGrid test;
    test.fillGrid();
    test.printGrid();
    return 0;
}





