#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#include "drawing.h"

#define DISPLAY_WIDTH  240
#define DISPLAY_HEIGHT 320
#define BLOCK_SIZE 24
//#define BOARD_WIDTH 10
//#define BOARD_HEIGHT 12

void redrawGrid(int board[width][height]) {
	int blockX = 0;
	int blockY = DISPLAY_HEIGHT - BLOCK_SIZE;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (board[j][height-1-i] == 1) {
				tft.fillRect(blockX, blockY, BLOCK_SIZE, BLOCK_SIZE, ILI9341_RED);
				tft.drawRect(blockX, blockY, BLOCK_SIZE, BLOCK_SIZE, ILI9341_BLACK);
			}
			blockX += BLOCK_SIZE;
			if (j==width-1) {
				blockX = 0;
			}
		}
		blockY -= BLOCK_SIZE;
	}
}
