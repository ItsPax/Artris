#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
//#include <cstdlib>
//#include <SPI.h>

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
#define BOARD_HEIGHT 13

// joystick pins
#define JOY_HORIZ A0
#define JOY_VERT  A1
#define JOY_SEL   2

// constants for the joystick
#define JOY_DEADZONE 64
#define JOY_CENTER 512

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

int turnButton = 2;
int leftButton = 12;
int rightButton = 13;
int dropButton = 8;

int turn;
int left;
int right;
int drop;

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

		if ((millis()-time) > 350) {
			return 'n';
		}
	}
}

char joyInput() {
  int xVal = analogRead(JOY_HORIZ);
  int yVal = analogRead(JOY_VERT);
  //char input = 'n';
  time = millis();

  while (true) {
    if (yVal < JOY_CENTER - JOY_DEADZONE) {
      return 'a';
    }
    else if (yVal > JOY_CENTER + JOY_DEADZONE) {
      return 'd';
    }
    else if (xVal > JOY_CENTER + JOY_DEADZONE) {
      return ' ';
    }
    else if (xVal < JOY_CENTER - JOY_DEADZONE) {
      return 'q';
    }

    delay(10);
		//return input;
    if ((millis()-time) > 500) {
      return 'n';
    }
  }

}

void setup() {
  init();
	//pinMode(JOY_SEL, INPUT_PULLUP);
	Serial.begin(9600);
	tft.begin();
	tft.fillScreen(ILI9341_BLACK);

	pinMode(turnButton, INPUT);
	pinMode(leftButton, INPUT);
	pinMode(rightButton, INPUT);
	pinMode(dropButton, INPUT);
	digitalWrite(turnButton, HIGH);
	digitalWrite(leftButton, HIGH);
	digitalWrite(rightButton, HIGH);
	digitalWrite(dropButton, HIGH);
}

uint16_t rngToColour(uint16_t c) {
	if (c == 1) {
		return ILI9341_YELLOW;
	}
	else if (c == 2) {
		return ILI9341_PURPLE;
	}
	else if (c == 3) {
		return ILI9341_BLUE;
	}
	else if (c == 4) {
		return ILI9341_ORANGE;
	}
	else if (c == 5) {
		return ILI9341_CYAN;
	}
	else if (c == 6) {
		return ILI9341_GREEN;
	}
	else if (c == 7) {
		return ILI9341_RED;
	}
	else{
		return ILI9341_BLACK;
	}

}

// uint16_t getRandomU16() {
// 	uint16_t num = 0;
// 	for (int i = 0; i < 16; i++) {
// 		// shift the number over and add a random bit
// 		num = (num<<1) | (analogRead(A1)&1);
// 	}
// 	return num;
// }

void rngBoard(int board[BOARD_WIDTH][BOARD_HEIGHT]) {
	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			board[i][j] = random(101)%8;
		}
	}
}

void redrawGrid(int board[BOARD_WIDTH][BOARD_HEIGHT]) {
	rngBoard(board);
	int blockX = 0;
	int blockY = DISPLAY_HEIGHT - BLOCK_SIZE;
	uint16_t colour;

	for (int i = 0; i < BOARD_HEIGHT; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {

			colour = rngToColour(board[j][BOARD_HEIGHT-1-i]);
			tft.fillRect(blockX, blockY, BLOCK_SIZE, BLOCK_SIZE, colour);
			tft.drawRect(blockX, blockY, BLOCK_SIZE, BLOCK_SIZE, ILI9341_BLACK);

			blockX += BLOCK_SIZE;
			if (j==BOARD_WIDTH-1) {
				blockX = 0;
			}
		}
		blockY -= BLOCK_SIZE;
	}
}

int main() {
	setup();
	char input;
	int board[BOARD_WIDTH][BOARD_HEIGHT];
	while (true) {
		//input = joyInput();
		//input = buttonInput();
		//delay(150);
		//Serial.println(input);
		rngBoard(board);
		redrawGrid(board);
		delay(500);
	}

	Serial.end();
	return 0;
}
