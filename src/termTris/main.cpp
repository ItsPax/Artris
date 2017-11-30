
#include "frontier.h" 

int main()  {
    Frontier io;
    io.shouldSpawn = true;
    io.fillFrontier();
    io.printFrontier();
    int i = 0;
    while (true)    {
        io.turn();
        io.printFrontier();
        ++i;
        if (i == 20)    { // if you index out of range of the entire blocks[][], then the compiler kills the prog
            break;
        }
    }
    return 0;
}

