
#include "frontier.h" 

int main()  {
    Frontier io;
    io.fillFrontier();
    io.printFrontier();
    io.spawnBlock();
    int i = 0;
    while (i < 2)    {
        io.turn();
        io.printFrontier();
        ++i;
    }
    return 0;
}

