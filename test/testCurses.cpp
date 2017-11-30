#include <iostream>
#include <curses.h> // need to pass the compiler the flag -lncurses

using namespace std;

int main()  {
    // lets see if we can ignore the buffer
    char c = ' ';
    //while(true) {
        c = getch();
        cout << int(c) << '\n';
    //}

    return 0;
}
