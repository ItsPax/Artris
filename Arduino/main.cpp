#include <Arduino.h>
#include "frontier.h"
#include "drawing.h"
// #include <Adafruit_GFX.h>
// #include <Adafruit_ILI9341.h>
//#include <iostream>

// // joystick pins
// #define JOY_HORIZ A0
// #define JOY_VERT  A1
// #define JOY_SEL   2
//
// // constants for the joystick
// #define JOY_DEADZONE 64
// #define JOY_CENTER 512



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

// void setup() {
//   init();
// 	//pinMode(JOY_SEL, INPUT_PULLUP);
// 	Serial.begin(9600);
// 	tft.begin();
//   tft.fillScreen(ILI9341_BLACK);
//
//   pinMode(turnButton, INPUT);
// 	pinMode(leftButton, INPUT);
// 	pinMode(rightButton, INPUT);
// 	pinMode(dropButton, INPUT);
// 	digitalWrite(turnButton, HIGH);
// 	digitalWrite(leftButton, HIGH);
// 	digitalWrite(rightButton, HIGH);
// 	digitalWrite(dropButton, HIGH);
// }

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
      //delay(100);
	    io.turn(input);
	    io.printFrontier();
    }
    return 0;
}
