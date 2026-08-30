# AutoPlex14
### The most capable Arduino library for fourteen-segment displays
AutoPlex14 is one of the most powerful Arduino libraries for controlling 14-segment displays. Unlike traditional LED-display libraries, AutoPlex14 handles multiplexing seamlessly using a hardware timer; meaning you never need to refresh the display. This frees up the main loop() and permits blocking code while not display flicker.

### Features
* Background multiplexing
* Works with both common anode and common cathode displays
* Supports transistor drivers or direct display-to-microcontroller connection
* Full alphanumeric and partial Unicode support
* Custom fonts
* Floating-point autoranging
* Can control up to four automatically multiplexed displays with up to six digits each

#

### Installation
To use AutoPlex14 in an Arduino sketch, you'll first need to install it.

**STEP 1.** Locate the large green button labeled "Code" on this repository's homepage. Click on it and select the option "Download ZIP."

**STEP 2.** Launch the Arduino IDE and hover over "Sketch" at the top. Near the bottom of the numerous options that appear, you should find "Include library." Selecting this will open a new menu, where you'll find "Add .ZIP Library." Click this; then find and open AutoPlex14-main from your downloads folder.

The library is now ready.

### Initialization
Now that AutoPlex14 has been installed, it needs to be added to your sketch and configured to control your display.

At the top of your program, `#include` the library.
```C++
#include <AutoPlex14.h>
```

Directly beneath this, you can instantiate a 14-segment object. In this example, I'll name my object "MyDisplay," although you're free to use any name you like.
```C++
AutoPlex14 MyDisplay;
```

Next, we need to configure `MyDisplay`'s wiring and information by creating variables to hold it. This should be performed within `setup()`.
```C++
void setup() {
  bool displayType = /*Replace this comment with either COMMON_ANODE or COMMON_CATHODE*/;
  byte displayDigits = /*The number of digits your display has*/;
  byte digitPins[] = { /*DIGIT_1, DIGIT_2, DIGIT_3...*/ };
  byte segmentPins[] = { /*TOP_HORIZONTAL_SEGMENT,
                         UPPER_RIGHT_VERTICAL_SEGMENT
                         LOWER_RIGHT_VERTICAL_SEGMENT,
                         BOTTOM_HORIZONTAL_SEGMENT,
                         LOWER_LEFT_VERTICAL_SEGMENT,
                         UPPER_LEFT_VERTICAL_SEGMENT,
                         MIDDLE_LEFT_HORIZONTAL_SEGMENT
                         MIDDLE_RIGHT_HORIZONTAL_SEGMENT,
                         UPPER_LEFT_DIAGONAL_SEGMENT,
                         UPPER_MIDDLE_VERTICAL_SEGMENT,
                         UPPER_RIGHT_DIAGONAL_SEGMENT,
                         LOWER_RIGHT_DIAGONAL_SEGMENT,
                         LOWER_MIDDLE_VERTICAL_SEGMENT,
                         LOWER_LEFT_DIAGONAL_SEGMENT,
                         DECIMAL_POINT_SEGMENT*/
                       };
```
###### Be sure to replace the applicable comments with your display info and pin connections.

After you configure the parameters, you can initialize it by passing them to the `begin()` method.
```C++
  MyDisplay.begin(displayType, displayDigits, digitPins, segmentPins);
```

Next, it's standard practice to perform a display functionality test. Calling `testDisplay(unsigned long ms)` will light all segments and decimal points for a specified duration.
```C++
  MyDisplay.testDisplay(1000); // 1000 millisecond (1 second) test
```

The display startup process is now completed; and AutoPlex14 is ready for use.

### Controlling the display
AutoPlex14 features several built-in methods to manipulate the display.

#### Writing to the display
You can print integers, floats, and strings on the screen by using the `print()` method.
```C++
MyDisplay.print(1234); // Prints 1234 as an integer
```
```C++
MyDisplay.print(12.3456789, 2); // Prints 12.34 as a float, showing two digits after the decimal
```
```C++
MyDisplay.print(12.3456789); // Prints 12.3456789 as a float, and automatically determines where to truncate based on the display size
```
```C++
MyDisplay.print("HI."); // Prints the ASCII string "HI." onto the display
```
```C++
MyDisplay.print(U"±200µΩ"); // Prints the Unicode string "±200µΩ" onto the display
```
###### *NOTE 1: If you attempt to display a string containing a character the current font does not support, AutoPlex14 will default to showing a question mark.*
###### *NOTE 2: If an attempt is made to show a string or number that is too long to fit on the display, AutoPlex14 will render dashes instead.*

#### Appending characters to the display
AutoPlex14 also features an `append()` method. It is almost identical to `print()`, except that it does not replace the previous display contents; instead, it adds the new ones onto them.
###### *NOTE 1: Currently, `append()` does not support autoranging for floating point numbers. You must define how many digits to show after the decimal manually.*
###### *NOTE 2: it is strongly discouraged to use `append()` heavily with automated multiplexing. Should you choose to, you may notice significant flicker on the display. This is due to rendering of temporary or partially overwritten display states caused by interrupts. If you need to use the append() method often, it's best to disable automatic multiplexing and call multiplex() manually within loop(). Be aware that this will mandate non-blocking code.*

#### Clearing the display
Occasionally, you may find yourself needing to clear the display. This can be done using the `clear()` method.
```C++
MyDisplay.clear();
```

#### Custom fonts & characters
AutoPlex14 allows for creation and usage of custom fonts. Inside a font, you can define a bitmap for almost any character you want, excluding U+0000, U+002E, and the segment test. These characters are either pre-defined, independent of fonts, or simply cannot be overridden. To make a font...
```C++
font myNewFont = {
  { U'[character], 0b[bitmap] },
  { U'[character], 0b[bitmap] },
  ...
  { U'[character], 0b[bitmap] },
  END // Informs the renderer that it has reached the end of the font
};
```
###### *NOTE: Bitmaps are ordered: TOP_HORIZONTAL_SEGMENT, UPPER_RIGHT_VERTICAL_SEGMENT LOWER_RIGHT_VERTICAL_SEGMENT, BOTTOM_HORIZONTAL_SEGMENT, LOWER_LEFT_VERTICAL_SEGMENT, UPPER_LEFT_VERTICAL_SEGMENT, MIDDLE_LEFT_HORIZONTAL_SEGMENT, MIDDLE_RIGHT_HORIZONTAL_SEGMENT, UPPER_LEFT_DIAGONAL_SEGMENT, UPPER_MIDDLE_VERTICAL_SEGMENT, UPPER_RIGHT_DIAGONAL_SEGMENT, LOWER_RIGHT_DIAGONAL_SEGMENT, LOWER_MIDDLE_VERTICAL_SEGMENT, LOWER_LEFT_DIAGONAL_SEGMENT. A 1 represents an active segment, while a 0 represents an inactive segment.*

To activate the custom font, we would call:
```C++
MyDisplay.setFont(myNewFont);
```
Now, all characters printed in the future will be as defined by `myNewFont`.

You can revert back to the original font at any time.
```C++
MyDisplay.setFont(defaultFont);
```

### Advanced features
AutoPlex14 has many features designed for advanced users.

#### Manual multiplexing
Although by default, AutoPlex14 handles multiplexing in the background by using Timer1, it is possible to disable this. When you call `begin()` on a new display object, you may add a fifth argument "MANUALPLEX."
```C++
MyDisplay.begin(displayType, displayDigits, digitPins, segmentPins, MANUALPLEX);
```
Then, from `loop()` you'll need to repeatedly call:
```C++
MyDisplay.multiplex();
```
Be aware that this will mandate the use of non-blocking code, or else the display may flicker.

#### Multiple displays
AutoPlex14 can control up to four independent displays simultaneously. Below is an example implementation of how this can be done, using two 14-segment displays.
```C++
#include <AutoPlex14.h>

AutoPlex14 display1;
AutoPlex14 display2;

void setup() {
  bool displayType1 = COMMON_CATHODE;
  byte displayDigits1 = 2;
  byte digitPins1[] = {0, 1};
  byte segmentPins1[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  display1.begin(displayType1, displayDigits1, digitPins1, segmentPins1);
  bool displayType2 = COMMON_ANODE;
  byte displayDigits2 = 4;
  byte digitPins2[] = {17, 18, 19, 20};
  byte segmentPins2[] = {21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35};
  display2.begin(displayType2, displayDigits2, digitPins2, segmentPins2);
}
```

#### Transistor drivers
To achieve higher brightness, AutoPlex14 features support for transistor-driven displays. Using this is fairly straightforward; simply swap the displayType variable from type bool to byte, and set it's value to either CAWDDT (**C**ommon **A**node **W**ith **D**igit **D**rive **T**ransistors) or CCWDDT (**C**ommon **C**athode **W**ith **D**igit **D**rive **T**ransistors)
```C++
void setup() {
  byte displayType = /*CAWDDT or CCWDDT*/;
  ...
}
```
#
### Things to keep in mind
1. **Current limiting:** Always use appropriate current-limiting resistors (on digit pins for directly driven displays, and segment pins for transistor-driven displays)
2. **Timer1 conflicts:** This library uses Timer1, and thus may conflict with other libraries that do as well.
3. **Compatibility:** AutoPlex14 is only compatible with AVR boards.
#
### MIT License
Copyright (c) 2026 TechTronics

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
