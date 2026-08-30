/*
  Second Counter

  This sketch shows the amount of time that has passed since startup on a 4-digit 14-segment display. It also demonstrates how automatically applied autoranging functions and behaves.

  The circuit:
  - Display top horizontal segment pin -> Arduino digital pin 0
  - Display upper right vertical segment pin -> Arduino digital pin 1
  - Display lower right vertical segment pin -> Arduino digital pin 2
  - Display bottom horizontal segment pin -> Arduino digital pin 3
  - Display lower left vertical segment pin -> Arduino digital pin 4
  - Display upper left vertical segment pin -> Arduino digital pin 5
  - Display middle left horizontal segment pin -> Arduino digital pin 6
  - Display middle right horizontal segment pin -> Arduino digital pin 7
  - Display upper left diagonal segment pin -> Arduino digital pin 8
  - Display upper middle vertical segment pin -> Arduino digital pin 9
  - Display upper right diagonal segment pin -> Arduino digital pin 10
  - Display lower right diagonal segment pin -> Arduino digital pin 11
  - Display lower middle vertical segment pin -> Arduino digital pin 12
  - Display lower left diagonal segment pin -> Arduino digital pin 13
  - Display decimal point segment pin -> Arduino digital pin A0
  - Display digit pin 1 -> 270Ω -> Arduino pin A1
  - Display digit pin 2 -> 270Ω -> Arduino pin A2
  - Display digit pin 3 -> 270Ω -> Arduino pin A3
  - Display digit pin 4 -> 270Ω -> Arduino pin A4

  created 8/29/2026
  by Nyjah

  This example sketch is in the public domain.
*/

#include <AutoPlex14.h>

AutoPlex14 MyDisplay; // Create a display object named "MyDisplay"

void setup() {
  bool displayType = COMMON_CATHODE; // Change to "COMMON_ANODE" if using a common anode display
  byte digits = 4; // Four-digit display
  byte digitPins[] = { A1, A2, A3, A4 };
  byte segmentPins[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0 };
  MyDisplay.begin(displayType, digits, digitPins, segmentPins);
  MyDisplay.testDisplay(1000); // Light all segments for 1000 milliseconds (1 second)
}

void loop() {
  float seconds = (float)millis() / 1000.0; // Calculate the number of seconds since the last reset
  MyDisplay.print(seconds); // Show seconds on the display, with a moving decimal point and automatically determined precision
}
