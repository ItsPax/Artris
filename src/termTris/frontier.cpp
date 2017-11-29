#include <iostream>
#include <cstdlib> // for random

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
    cout << '\n';
}

void Frontier::spawnBlock() {
    int randomVar = rand()%WIDTH;
    blocks[randomVar][0] = 'A';
}

void Frontier::move(int i0, int j0, int i1, int j1) {
    blocks[i1][j1] = blocks[i0][j0];
    blocks[i0][j0] = '.';
}

void Frontier::turn()   {
    for (int j = 0; j < HEIGHT; ++j) {
        for (int i = 0; i < WIDTH; ++i) {
            if (blocks[i][j] == 'A')    {
                cout << i << ' ' << j << endl;
                move(i,j,i+1,j);
            }
        }
    }
}

