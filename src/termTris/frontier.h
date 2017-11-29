#ifndef FRONTIER_H

const int WIDTH = 10;
const int HEIGHT = 12;

#define FRONTIER_H

class Frontier  {
    char blocks[WIDTH][HEIGHT];
public:
    void printFrontier();
    void fillFrontier();
    void spawnBlock();
    void turn();
    void move(int a,int b, int c, int d);
};

#endif
