#ifndef FRONTIER_H

const int WIDTH = 10;
const int HEIGHT = 12;
const int TIME_TICKS = 500000;

#define FRONTIER_H

class Frontier  {
    char blocks[WIDTH][HEIGHT];
public:
    // variables 
    bool shouldSpawn;
    bool isDead[WIDTH][HEIGHT];

    void printFrontier();
    void fillFrontier();
    void spawnBlock();
    void turn();
    void move(int a,int b, int c, int d);
    bool isOccupied(int i, int j);
    bool isInBounds(int,int);
};

#endif
