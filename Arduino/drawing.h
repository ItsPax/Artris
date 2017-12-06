#ifndef _DRAWING_H
#define _DRAWING_H

uint16_t charToColour(char c);
void redrawGrid(int board[width][height]);
// void redrawShape(int xPos, int yPos, int blockShape);
void drawSingleBlock(char c, int x, int y);

#endif
