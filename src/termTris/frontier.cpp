#include <iostream>
#include <cstdlib> // for random
#include <unistd.h> // for usleep

#include "frontier.h"

using namespace std;

void Frontier::fillFrontier() {
    for (int j = 0; j < HEIGHT; ++j) {
        for (int i = 0; i < WIDTH; ++i) {
            blocks[i][j] = '.';
        }
    }
}

void Frontier::printFrontier()  {
    for (int j = 0; j < HEIGHT; ++j) {
        for (int i = 0; i < WIDTH; ++i) {
            cout << blocks[i][j];
        }
        cout << '\n';
    }
    cout << '\n' << flush;
}

void Frontier::spawnBlock() {
    int randomVar = rand()%WIDTH;
    blocks[randomVar][0] = 'A';
}

bool Frontier::isOccupied(int i, int j)  {
    return (blocks[i][j] != '.');
}

bool Frontier::isInBounds(int i, int j)   {
    return (j < HEIGHT && i > 0 && i < WIDTH);
}

void Frontier::move(int i0, int j0, int i1, int j1) {
    if (!isOccupied(i1,j1) && isInBounds(i1,j1))    {
        blocks[i1][j1] = blocks[i0][j0];
        blocks[i0][j0] = '.';
    } else  {
        if (!isDead[i0][j0])    {
            isDead[i0][j0] = true;
            shouldSpawn = true;
        }
    }
}

void Frontier::turn()   {
    // implement stepping 
    for (int i = 0; i < TIME_TICKS/1000; ++i)   {
        usleep(TIME_TICKS/1000);
        char c = cin.peek(); // this allows me to check the buffer for input
        cout << c << flush; 
    }
    if (shouldSpawn)    { // handle block spawning
        shouldSpawn = false;
        spawnBlock();
    }
    for (int j = HEIGHT-1; j >= 0; --j) {
        for (int i = WIDTH-1; i >= 0; --i) {
            if (blocks[i][j] == 'A')    {
                move(i,j,i,j+1);
            }
        }
    }
}

