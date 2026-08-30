/*
  Test Display

  This sketch plays various animations on a 4-digit 14-segment display, while also demonstarting core features of AutoPlex14.

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

font individualSegments = { // A font that represents individual segments turned on
  { U'0', 0b10000000000000 },
  { U'1', 0b01000000000000 },
  { U'2', 0b00100000000000 },
  { U'3', 0b00010000000000 },
  { U'4', 0b00001000000000 },
  { U'5', 0b00000100000000 },
  { U'6', 0b00000010000000 },
  { U'7', 0b00000001000000 },
  { U'7', 0b00000000100000 },
  { U'8', 0b00000000010000 },
  { U'9', 0b00000000001000 },
  { U'A', 0b00000000000100 },
  { U'B', 0b00000000000010 },
  { U'C', 0b00000000000001 },
  END
};

void cyclePlex() { // A multiplexing animation that cycles through segments at increasing speeds, and then turns them all on
  MyDisplay.setFont(individualSegments);
  for (unsigned int i = 50; i > 0; i--) { // Increase speed each cycle
    MyDisplay.print("0000");
    delay(i);
    MyDisplay.print("1111");
    delay(i);
    MyDisplay.print("2222");
    delay(i);
    MyDisplay.print("3333");
    delay(i);
    MyDisplay.print("4444");
    delay(i);
    MyDisplay.print("5555");
    delay(i);
    MyDisplay.print("6666");
    delay(i);
    MyDisplay.print("7777");
    delay(i);
    MyDisplay.print("8888");
    delay(i);
    MyDisplay.print("9999");
    delay(i);
    MyDisplay.print("AAAA");
    delay(i);
    MyDisplay.print("BBBB");
    delay(i);
    MyDisplay.print("CCCC");
    delay(i);
  }
  MyDisplay.testDisplay(1000); // Light all segments for 1000 milliseconds (1 second)
  MyDisplay.setFont(defaultFont); // Return to default font
  MyDisplay.clear(); // Clear the display
  delay(150); // Small pause
}

void helloWorld() { // This function draws a scrolling "HELLO WORLD" animation
  MyDisplay.print("   H");
  delay(150);
  MyDisplay.print("  HE");
  delay(150);
  MyDisplay.print(" HEL");
  delay(150);
  MyDisplay.print("HELL");
  delay(150);
  MyDisplay.print("ELLO");
  delay(150);
  MyDisplay.print("LLO ");
  delay(150);
  MyDisplay.print("LO W");
  delay(150);
  MyDisplay.print("O WO");
  delay(150);
  MyDisplay.print(" WOR");
  delay(150);
  MyDisplay.print("WORL");
  delay(150);
  MyDisplay.print("ORLD");
  delay(150);
  MyDisplay.print("RLD ");
  delay(150);
  MyDisplay.print("LD  ");
  delay(150);
  MyDisplay.print("D   ");
  delay(150);
  MyDisplay.clear();
  delay(150);
}

void setup() {
  bool displayType = COMMON_CATHODE; // Change to "COMMON_ANODE" if using a common anode display
  byte digits = 4; // Four-digit display
  byte digitPins[] = { A1, A2, A3, A4 };
  byte segmentPins[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
  MyDisplay.begin(displayType, digits, digitPins, segmentPins);
  cyclePlex();
  helloWorld();
}

void loop() {
  MyDisplay.print(1234);
  delay(500);
  MyDisplay.print(2345);
  delay(150);
  MyDisplay.print(3456);
  delay(150);
  MyDisplay.print(4567);
  delay(150);
  MyDisplay.print(5678);
  delay(150);
  MyDisplay.print(6789);
  delay(500);
  MyDisplay.print("6.789");
  delay(500);
  MyDisplay.print("6.7.89");
  delay(150);
  MyDisplay.print("6.7.8.9");
  delay(150);
  MyDisplay.print("6.7.8. ");
  delay(50);
  MyDisplay.print("6.7.8 ");
  delay(50);
  MyDisplay.print("6.7.  ");
  delay(50);
  MyDisplay.print("6.7  ");
  delay(50);
  MyDisplay.print("6.   ");
  delay(50);
  MyDisplay.print("6   ");
  delay(50);
  MyDisplay.clear();
  delay(500);
  MyDisplay.print("ABCD");
  delay(500);
  MyDisplay.print("EFGH");
  delay(500);
  MyDisplay.print("IJKL");
  delay(500);
  MyDisplay.print("MNOP");
  delay(500);
  MyDisplay.print("QRST");
  delay(500);
  MyDisplay.print("UVWX");
  delay(500);
  MyDisplay.print(" YZ ");
  delay(500);
  MyDisplay.clear();
  delay(500);
}
