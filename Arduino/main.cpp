#include <Arduino.h>
#include "frontier.h"
//#include <iostream>

// // joystick pins
// #define JOY_HORIZ A0
// #define JOY_VERT  A1
// #define JOY_SEL   2
//
// // constants for the joystick
// #define JOY_DEADZONE 64
// #define JOY_CENTER 512

int turnButton = 2;
int leftButton = 12;
int rightButton = 13;
int dropButton = 8;

int turn;
int left;
int right;
int drop;

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
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

// char joyInput() {
//   int xVal = analogRead(JOY_HORIZ);
//   int yVal = analogRead(JOY_VERT);
//   char input = 'n';
//   time = millis();
//
//   while (true) {
//     if (yVal < JOY_CENTER - JOY_DEADZONE) {
//       input = 'a';
//     }
//     else if (yVal > JOY_CENTER + JOY_DEADZONE) {
//       input = 'd';
//     }
//     else if (xVal > JOY_CENTER + JOY_DEADZONE) {
//       input = ' ';
//     }
//     else if (xVal < JOY_CENTER - JOY_DEADZONE) {
//       input = 'q';
//     }
//
//     delay(20);
//     if ((millis()-time) > 500) {
//       return input;
//     }
//   }
//
// }

void setup() {
  init();
	pinMode(JOY_SEL, INPUT_PULLUP);
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

int main()  {
    setup();

    char input;
    // consider tossing all of the below into an initalize() function
    // initializes game
    Frontier io;
    //io.highScore = 0;
    io.fillFrontierWithDots();
    io.setAllDead();
    io.initializeGame();
    io.resetGhostGrid();

    // handles game mechanics
    while(true)	{
      input = buttonInput();
      delay(150);
	    io.turn(input);
	    io.printFrontier();
    }
    return 0;
}
