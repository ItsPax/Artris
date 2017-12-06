#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#include "drawing.h"

// TFT display and SD card will share the hardware SPI interface.
// For the Adafruit shield, these are the default.
// The display uses hardware SPI, plus #9 & #10
// Mega2560 Wiring: connect TFT_CLK to 52, TFT_MISO to 50, and TFT_MOSI to 51.
#define TFT_DC 9
#define TFT_CS 10
#define SD_CS 6

// width/height of the display
#define DISPLAY_WIDTH  240
#define DISPLAY_HEIGHT 320
#define BLOCK_SIZE 24
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 12

uint16_t charToColour(char c) {
	if (c == 'Y') {
		return ILI9341_YELLOW;
	}
	else if (c == 'P') {
		return ILI9341_PURPLE;
	}
	else if (c == 'B') {
		return ILI9341_BLUE;
	}
	else if (c == 'O') {
		return ILI9341_ORANGE;
	}
	else if (c == 'C') {
		return ILI9341_CYAN;
	}
	else if (c == 'G') {
		return ILI9341_GREEN;
	}
	else if (c == 'R') {
		return ILI9341_RED;
	}
	else if (c == '*') {
		return ILI9341_BLACK;
	}
	else (c == '.') {
		return ILI9341_BLACK;
	}

}

void redrawGrid(int board[BOARD_WIDTH][BOARD_HEIGHT]) {
	int blockX = 0;
	int blockY = DISPLAY_HEIGHT - BLOCK_SIZE;
	uint16_t colour;

	for (int i = 0; i < BOARD_HEIGHT; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			//if (board[j][BOARD_HEIGHT-1-i] == 1) {
			colour = charToColour(board[j][BOARD_HEIGHT-1-i]);
			tft.fillRect(blockX, blockY, BLOCK_SIZE, BLOCK_SIZE, colour);
			tft.drawRect(blockX, blockY, BLOCK_SIZE, BLOCK_SIZE, ILI9341_BLACK);
			//}
			blockX += BLOCK_SIZE;
			if (j==BOARD_WIDTH-1) {
				blockX = 0;
			}
		}
		blockY -= BLOCK_SIZE;
	}
}

void drawSingleBlock(char c, int x, int y) {
	int blockX = x*BLOCK_SIZE;
	int blockY = DISPLAY_HEIGHT-(1+y)*BLOCK_SIZE;
	uint16_t colour;
	colour = charToColour(c);
	tft.fillRect(blockX, blockY, BLOCK_SIZE, BLOCK_SIZE, ILI9341_RED);
	if (c == '*') {
		tft.drawRect(blockX, blockY, BLOCK_SIZE, BLOCK_SIZE, ILI9341_WHITE);
	}
	tft.drawRect(blockX, blockY, BLOCK_SIZE, BLOCK_SIZE, ILI9341_BLACK);
}
