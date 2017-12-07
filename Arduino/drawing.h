#ifndef _DRAWING_H
#define _DRAWING_H

// width/height of the display
#define DISPLAY_WIDTH  240
#define DISPLAY_HEIGHT 320
#define BLOCK_SIZE 24
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 12

uint16_t charToColour(char c);
void redrawGrid(int board[BOARD_WIDTH][BOARD_HEIGHT]);
// void redrawShape(int xPos, int yPos, int blockShape);
void drawSingleBlock(char c, int x, int y);
char buttonInput();
void setup();

#endif
