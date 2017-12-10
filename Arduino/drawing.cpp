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

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

int turnButton = 2;
int leftButton = 12;
int rightButton = 13;
int dropButton = 8;

int turn;
int left;
int right;
int drop;

void setup() {
  init();
	//pinMode(JOY_SEL, INPUT_PULLUP);
	Serial.begin(9600);
	tft.begin();
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0,0);
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
  tft.setTextSize(2);
  tft.print("Score: ");

  pinMode(turnButton, INPUT);
	pinMode(leftButton, INPUT);
	pinMode(rightButton, INPUT);
	pinMode(dropButton, INPUT);
	digitalWrite(turnButton, HIGH);
	digitalWrite(leftButton, HIGH);
	digitalWrite(rightButton, HIGH);
	digitalWrite(dropButton, HIGH);
}

unsigned long time;

char buttonInput() {
	time = millis();
	while (true) {
		turn = digitalRead(turnButton);
		left = digitalRead(leftButton);
		right = digitalRead(rightButton);
		drop = digitalRead(dropButton);


		if (turn == LOW) {
			return 'q';
		}
		else if (left == LOW) {
			return 'a';
		}
		else if (right == LOW) {
			return 'd';
		}
		else if (drop == LOW) {
			return ' ';
		}

		if ((millis()-time) > 300) {
			return 'n';
		}
	}
}

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
	else {
		return ILI9341_BLACK;
	}

}

// void redrawGrid(int board[BOARD_WIDTH][BOARD_HEIGHT]) {
// 	int blockX = 0;
// 	int blockY = DISPLAY_HEIGHT - BLOCK_SIZE;
// 	uint16_t colour;
//
// 	for (int i = 0; i < BOARD_HEIGHT; i++) {
// 		for (int j = 0; j < BOARD_WIDTH; j++) {
// 			//if (board[j][BOARD_HEIGHT-1-i] == 1) {
// 			colour = charToColour(board[j][BOARD_HEIGHT-1-i]);
// 			tft.fillRect(blockX, blockY, BLOCK_SIZE, BLOCK_SIZE, colour);
// 			tft.drawRect(blockX, blockY, BLOCK_SIZE, BLOCK_SIZE, ILI9341_BLACK);
// 			//}
// 			blockX += BLOCK_SIZE;
// 			if (j==BOARD_WIDTH-1) {
// 				blockX = 0;
// 			}
// 		}
// 		blockY -= BLOCK_SIZE;
// 	}
// }

void drawSingleBlock(char c, int x, int y) {
	int blockX = x*BLOCK_SIZE;
	int blockY = DISPLAY_HEIGHT-(BOARD_HEIGHT-y)*BLOCK_SIZE;
	uint16_t colour;
	colour = charToColour(c);
	tft.fillRect(blockX, blockY, BLOCK_SIZE, BLOCK_SIZE, colour);
	if (c == '*') {
		tft.drawRect(blockX, blockY, BLOCK_SIZE, BLOCK_SIZE, ILI9341_WHITE);
	}
	else {
		tft.drawRect(blockX, blockY, BLOCK_SIZE, BLOCK_SIZE, ILI9341_BLACK);
	}
}

void printScore(int score) {
  tft.setCursor(80,0);
  tft.print(score);
  tft.print("     ");
}
