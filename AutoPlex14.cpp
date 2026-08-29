#include "AutoPlex14.h"

font systemFont[] = {
  { U'0', 0b11111111111111 }, // Display test
  END
};
font defaultFont[] = {
  { U' ', 0b00000000000000 }, // Space
  { U'0', 0b11111100001001 }, // Zero
  { U'1', 0b01100000001000 }, // One
  { U'2', 0b11011011000000 }, // Two
  { U'3', 0b10110011001000 }, // Three
  { U'4', 0b01100111000000 }, // Four
  { U'5', 0b10110111000000 }, // Five
  { U'6', 0b10111111000000 }, // Six
  { U'7', 0b10000000001010 }, // Seven
  { U'8', 0b11111111000000 }, // Eight
  { U'9', 0b11110111000000 }, // Nine
  { U'-', 0b00000011000000 }, // Hyphen
  { U'_', 0b00010000000000 }, // Underscore
  { U'+', 0b00000011010010 }, // Plus
  { U'=', 0b10000011000000 }, // Equals
  { U'|', 0b00000000010010 }, // Vertical pipe
  { U'*', 0b00000011111111 }, // Asterisk
  { U'/', 0b00000000001001 }, // Forward slash
  { U'>', 0b00000000100001 }, // Greater than
  { U'<', 0b00000000001100 }, // Less than
  { U'?', 0b11000001000010 }, // Question
  { U'!', 0b00010000010000 }, // Exclamation
  { U'@', 0b11110101000010 }, // At
  { U'#', 0b11111111010010 }, // Hashtag
  { U',', 0b00000000000001 }, // Comma
  { U'`', 0b00000000100000 }, // Backtick
  { U'%', 0b00100100001001 }, // Percent
  { U'^', 0b11000100000000 }, // Caret
  { U'&', 0b10011110011110 }, // Ampersand
  { U'(', 0b00000000001100 }, // Opening parenthesis
  { U')', 0b00000000100001 }, // Closing parenthesis
  { U'{', 0b01100001000000 }, // Opening curly brace
  { U'}', 0b00001110000000 }, // Closing curly brace
  { U'[', 0b10011100000000 }, // Opening square bracket
  { U']', 0b11110000000000 }, // Closing square bracket
  { U'~', 0b00101010000100 }, // Tilde
  { U'"', 0b01000100000000 }, // Double quotes
  { U'€', 0b10011110000000 }, // Euro
  { U'¢', 0b10011100010010 }, // Cent
  { U'$', 0b10110111010010 }, // Dollar
  { U'°', 0b11000111000000 }, // Degree
  { U'£', 0b10011110000000 }, // Pound
  { U'⁋', 0b11001101010010 }, // Paragraphus
  { U'₩', 0b01101111000101 }, // Won
  { U'A', 0b01100001001001 }, // Uppercase A
  { U'a', 0b11111011000000 }, // Lowercase a
  { U'B', 0b11110001010010 }, // Uppercase B
  { U'b', 0b00111111000000 }, // Lowercase b
  { U'C', 0b10011100000000 }, // Uppercase C
  { U'c', 0b00011011000000 }, // Lowercase c
  { U'D', 0b11110000010010 }, // Uppercase D
  { U'd', 0b01111011000000 }, // Lowercase d
  { U'E', 0b10011111000000 }, // Uppercase E
  { U'e', 0b10011110001000 }, // Lowercase e
  { U'F', 0b10001111000000 }, // Uppercase F
  { U'f', 0b10001110000000 }, // Lowercase f
  { U'G', 0b10111101000000 }, // Uppercase G
  { U'g', 0b11110001100000 }, // Lowercase g
  { U'H', 0b01101111000000 }, // Uppercase H
  { U'h', 0b00101111000000 }, // Lowercase h
  { U'I', 0b10010000010010 }, // Uppercase I
  { U'i', 0b10000000000010 }, // Lowercase i
  { U'J', 0b01110000000000 }, // Uppercase J
  { U'j', 0b01111000000000 }, // Lowercase j
  { U'K', 0b00001110001100 }, // Uppercase K
  { U'k', 0b00001110001100 }, // Lowercase k
  { U'L', 0b00011100000000 }, // Uppercase L
  { U'l', 0b00000000010010 }, // Lowercase l
  { U'M', 0b01101100101000 }, // Uppercase M
  { U'm', 0b00101011000010 }, // Lowercase m
  { U'N', 0b01101100100100 }, // Uppercase N
  { U'n', 0b00101011000000 }, // Lowercase n
  { U'O', 0b11111100000000 }, // Uppercase O
  { U'o', 0b00111011000000 }, // Lowercase o
  { U'P', 0b11001111000000 }, // Uppercase P
  { U'p', 0b11001111000000 }, // Lowercase p
  { U'Q', 0b11111100000100 }, // Uppercase Q
  { U'q', 0b11100111000000 }, // Lowercase q
  { U'R', 0b11001111000100 }, // Uppercase R
  { U'r', 0b00001011000000 }, // Lowercase r
  { U'S', 0b10110111000000 }, // Uppercase S
  { U's', 0b10110111000000 }, // Lowercase s
  { U'T', 0b10000000010010 }, // Uppercase T
  { U't', 0b00011111000000 }, // Lowercase t
  { U'U', 0b01111100000000 }, // Uppercase U
  { U'u', 0b00111000000000 }, // Lowercase u
  { U'V', 0b00001100001001 }, // Uppercase V
  { U'v', 0b00001100001001 }, // Lowercase v
  { U'W', 0b01101100000101 }, // Uppercase W
  { U'w', 0b00111000000010 }, // Lowercase w
  { U'X', 0b00000000101101 }, // Uppercase X
  { U'x', 0b00000000101101 }, // Lowercase x
  { U'Y', 0b00000000101010 }, // Uppercase Y
  { U'y', 0b01110111000000 }, // Lowercase y
  { U'Z', 0b10010000001001 }, // Uppercase Z
  { U'z', 0b10010000001001 }, // Lowercase z
  { U'×', 0b00000000101101 }, // Multiplication
  { U'μ', 0b00001111010000 }, // Mu
  { U'µ', 0b00001111010000 }, // Micro
  { U'⏻', 0b00111011010000 }, // Power
  { U'±', 0b00010011010010 }, // Plus/minus
  { U'¥', 0b00000011101010 }, // Yen
  { U'Ω', 0b11000111000101 }, // Omega
  END
};

uint8_t _displayIndex = 0; // The array index of the last display instance

    size_t AutoPlex14::strlen32(const char32_t* string) { // A helper function - used internally - for determining the length of a 32-bit character array
      size_t len = 0;
      for (uint8_t i = 0; string[i] != U'\0'; i++) { len++; }
      return len;
    }

    char32_t* AutoPlex14::strcpy32(char32_t* dest, const char32_t* src) { // Used internally to copy a 32-bit char array into another
      char32_t* original = dest;
      while ((*dest++ = *src++) != U'\0');
      return original;
    }

    char32_t* AutoPlex14::strcpy8to32(char32_t* dest, const char* src) { // Used internally to copy an 8 bit string into a 32 bit string
      char32_t* original = dest;
      uint8_t endIndex = 0;
      for (uint8_t i = 0; src[i] != '\0'; i++) {
        dest[i] = (char32_t)src[i];
        endIndex++;
      }
      dest[endIndex] = U'\0';
      return original;
    }

    size_t AutoPlex14::filterDecimals(const char32_t* string) { // Used internally to count how many non-decimal characters are in a wide character array
      size_t count = 0;
      for (uint8_t i = 0; i < strlen32(string); i++) {
        if (string[i] != U'.') { count++; }
      }
      return count;
    }

    size_t AutoPlex14::filterDecimals(const char* string) { // Used internally to count how many non-decimal characters are in a character array
      size_t count = 0;
      for (uint8_t i = 0; i < strlen(string); i++) {
        if (string[i] != '.') { count++; }
      }
      return count;
    }

    void AutoPlex14::wipeDisplay() { // Used internally to turn the display off without clearing the buffer
      for (uint8_t i = 0; i < digitsClass; i++) { digitalWrite(digitPinsClass[i], digitOff); }
      for (uint8_t i = 0; i < 15; i++) { digitalWrite(segmentPinsClass[i], segmentOff); }
    }

    bool AutoPlex14::begin(uint8_t displayType, uint8_t digits, uint8_t digitPins[], uint8_t segmentPins[], bool multiplexing) { // Initializes the display; returns true if successful
      if (digits > MAX_DIGITS || digits < 1) { return false; } // Validate arguments
      // Decide based on the type of display what "on" represents
      switch (displayType) {
        case COMMON_ANODE: segmentOn = LOW; digitOn = HIGH; break;
        case COMMON_CATHODE: segmentOn = HIGH; digitOn = LOW; break;
        case CAWDDT: segmentOn = LOW; digitOn = LOW; break;
        case CCWDDT: segmentOn = HIGH; digitOn = HIGH; break;
        default: return false; break;
      }
      // Define "off" as the inverse of "on"
      segmentOff = !segmentOn;
      digitOff = !digitOn;

      digitsClass = digits; // Store the number of digits on the display inside the class
      for (uint8_t i = 0; i < digitsClass; i++) { digitPinsClass[i] = digitPins[i]; } // Save digit pins to the class
      for (uint8_t i = 0; i < 15; i++) { segmentPinsClass[i] = segmentPins[i]; } // Save segment pins to class

      if (multiplexing == AUTOPLEX) { // Check if multiplexing should be performed automatically
        // If so, and too many displays have already been registered, that's an error
        if (_displayIndex >= MAX_DISPLAYS) {
          return false;
        }
        manualplexing = false;
        noInterrupts();
        displays[_displayIndex++] = this; // Register new display instance
        if (!timerConfigured) { // If it hasn't already been set up, configure Timer1 for automatic multiplexing
          TCCR1A = 0;
          TCCR1B = 0;
          TCNT1  = 0;
          OCR1A = 249;
          TCCR1B |= (1 << WGM12);
          TCCR1B |= (1 << CS11) | (1 << CS10);
          TIMSK1 |= (1 << OCIE1A);
          timerConfigured = true;
        }
        interrupts();
      }else{
        manualplexing = true;
      }

      // Configure display pins as outputs
      for (uint8_t i = 0; i < digitsClass; i++) { pinMode(digitPinsClass[i], OUTPUT); }
      for (uint8_t i = 0; i < 15; i++) { pinMode(segmentPinsClass[i], OUTPUT); }

      clear(); // Ensure display is blank
      return true;
    }
    void AutoPlex14::clear() { // Empty the display buffer and deactivate all digits and segments
      noInterrupts();
      buffer[0] = U'\0';
      displayPos = 0; bufferPos = 0;
      wipeDisplay();
      interrupts();
    }
    void AutoPlex14::setFont(font* newFont) {
      noInterrupts();
      currentFont = newFont;
      displayPos = 0; bufferPos = 0;
      interrupts();
    }
    void AutoPlex14::print(const char32_t* text) { // Shows a string on the display; works with any Unicode character the selected font defines
      noInterrupts();
      if (filterDecimals(text) > digitsClass) { // If new string does NOT fit on the display...
        // Show dashes instead
        uint8_t position = 0;
        for (uint8_t i = 0; i < digitsClass; i++) {
          buffer[position++] = U'-';
        }
        buffer[position] = U'\0'; // Terminate string
      }else{
        strcpy32(buffer, text); // Else copy the new string into the buffer for display contents
      }
      displayPos = 0; bufferPos = 0;
      interrupts();
    }
    void AutoPlex14::print(const char* text) { // Shows a string on the display; only works with ASCII characters
      noInterrupts();
      if (filterDecimals(text) > digitsClass) { // If new string does NOT fit on the display...
        // Show dashes
        uint8_t position = 0;
        for (uint8_t i = 0; i < digitsClass; i++) {
          buffer[position++] = U'-';
        }
        buffer[position] = U'\0'; // Terminate string
      }else{
        strcpy8to32(buffer, text); // Else paste the new contents into the buffer
      }
      displayPos = 0; bufferPos = 0;
      interrupts();
    }
    void AutoPlex14::print(int num) { // Set the fourteen segment display's buffer to an integer
      char temporary[11];
      itoa(num, temporary, 10);
      noInterrupts();
      if (strlen(temporary) > digitsClass) { // If number is too large to fit on the display...
        // Print dashes instead
        uint8_t position = 0;
        for (uint8_t i = 0; i < digitsClass; i++) {
          buffer[position++] = U'-';
        }
        buffer[position] = U'\0'; // Terminate string
      }else{
        strcpy8to32(buffer, temporary); // Else, paste the number into the display buffer
      }
      displayPos = 0; bufferPos = 0;
      interrupts();
    }
    void AutoPlex14::print(double num) { // Set the fourteen segment display's buffer to a double/float
      int32_t numInt = num; // Truncate the float into an integer
      char numIntString[11]; itoa(numInt, numIntString, 10); // Create a string containing the input as an integer
      uint16_t decimalPlaces = digitsClass - strlen(numIntString); // Clculate how many decimal places can fit on the display
      char temporary[11]; dtostrf(num, 0, decimalPlaces, temporary); // Create a string for the display
      noInterrupts();
      if (filterDecimals(temporary) > digitsClass) { // If the new number is too large for the display...
        // Show dashes
        uint8_t position = 0;
        for (uint8_t i = 0; i < digitsClass; i++) {
          buffer[position++] = U'-';
        }
        buffer[position] = U'\0'; // Terminate string
      }else{
        strcpy8to32(buffer, temporary); // Copy the number into the display buffer
      }
      interrupts();
    }
    void AutoPlex14::print(double num, uint8_t decimalPlaces) { // Set the fourteen segment display's buffer to a double/float, with a fixed number of digits after the decimal point
      char temporary[11];
      dtostrf(num, 0, decimalPlaces, temporary);
      noInterrupts();
      if (filterDecimals(temporary) > digitsClass) { // If number too large for display...
        // Show dashes
        uint8_t position = 0;
        for (uint8_t i = 0; i < digitsClass; i++) {
          buffer[position++] = U'-';
        }
        buffer[position] = U'\0'; // Terminate string
      }else{
        strcpy8to32(buffer, temporary); // Copy the new number into the buffer
      }
      displayPos = 0; bufferPos = 0;
      interrupts();
    }
    void AutoPlex14::append(const char32_t* text) { // Add a 32-bit string suffix to the current display contents
      noInterrupts();
      if (filterDecimals(buffer) + filterDecimals(text) > digitsClass) { // If the current display contents + new contents is longer than the display...
        // Show dashes instead
        uint8_t position = 0;
        for (uint8_t i = 0; i < digitsClass; i++) {
          buffer[position++] = U'-';
        }
        buffer[position] = U'\0'; // Terminate string
        interrupts();
        return;
      }
      uint8_t i = 0;
      while (buffer[i] != U'\0') { i++; } // Find the number of indexes before termination
      for (uint8_t u = 0; text[u] != U'\0'; u++) { // Add the suffix
        buffer[i++] = text[u];
      }
      buffer[i] = U'\0'; // Terminate string
      displayPos = 0; bufferPos = 0;
      interrupts();
    }
    void AutoPlex14::append(const char* text) { // Add an ASCII string suffix to the current display contents
      noInterrupts();
      if (filterDecimals(buffer) + filterDecimals(text) > digitsClass) { // If the current display contents + new contents is longer than the display...
        // Show dashes instead
        uint8_t position = 0;
        for (uint8_t i = 0; i < digitsClass; i++) {
          buffer[position++] = U'-';
        }
        buffer[position] = U'\0'; // Terminate string
        interrupts();
        return;
      }
      uint8_t i = 0;
      while (buffer[i] != U'\0') { i++; } // Find the number of indexes before termination
      for (uint8_t u = 0; text[u] != U'\0'; u++) { // Add the suffix
        buffer[i++] = (char32_t)text[u];
      }
      buffer[i] = U'\0'; // Terminate string
      displayPos = 0; bufferPos = 0;
      interrupts();
    }
    void AutoPlex14::append(int num) { // Add an integer suffix to the current display contents
      char string8[11];
      itoa(num, string8, 10);
      char32_t string32[11];
      strcpy8to32(string32, string8);
      noInterrupts();
      if (filterDecimals(buffer) + strlen32(string32) > digitsClass) { // If the current display contents + new contents is longer than the display...
        // Show dashes instead
        uint8_t position = 0;
        for (uint8_t i = 0; i < digitsClass; i++) {
          buffer[position++] = U'-';
        }
        buffer[position] = U'\0'; // Terminate string
        interrupts();
        return;
      }
      uint8_t i = 0;
      while (buffer[i] != U'\0') { i++; } // Find the number of indexes before termination
      for (uint8_t u = 0; string32[u] != U'\0'; u++) { // Add the suffix
        buffer[i++] = string32[u];
      }
      buffer[i] = U'\0'; // Terminate string
      displayPos = 0; bufferPos = 0;
      interrupts();
    }
    void AutoPlex14::append(double num, uint8_t decimalPlaces) { // Add a double suffix to the current display contents
      char string8[11];
      dtostrf(num, 0, decimalPlaces, string8);
      char32_t string32[11];
      strcpy8to32(string32, string8);

      noInterrupts();
      if (filterDecimals(buffer) + filterDecimals(string32) > digitsClass) { // If the current display contents + new contents is longer than the display...
        // Show dashes instead
        uint8_t position = 0;
        for (uint8_t i = 0; i < digitsClass; i++) {
          buffer[position++] = U'-';
        }
        buffer[position] = U'\0'; // Terminate string
        interrupts();
        return;
      }
      uint8_t i = 0;
      while (buffer[i] != U'\0') { i++; } // Find the number of indexes before termination
      for (uint8_t u = 0; string32[u] != U'\0'; u++) { // Add the suffix
        buffer[i++] = string32[u];
      }
      buffer[i] = U'\0'; // Terminate string
      displayPos = 0; bufferPos = 0;
      interrupts();
    }
    void AutoPlex14::testDisplay(unsigned long ms) {
      uint8_t position = 0;
      font* lastFont = currentFont;
      noInterrupts();
      currentFont = systemFont;
      for (uint8_t i = 0; i < digitsClass; i++) {
        buffer[position++] = U'0'; // Light all segments
        buffer[position++] = U'.'; // Light decimal point
      }
      buffer[position] = U'\0';
      interrupts();
      unsigned long testStart = millis();
      unsigned long lastPlex = millis();
      while (millis() - testStart < ms) { if (manualplexing && millis() - lastPlex >= 1) { lastPlex = millis(); multiplex(); } }
      noInterrupts();
      currentFont = lastFont;
      buffer[0] = U'\0';
      interrupts();
    }
    void AutoPlex14::multiplex() { // Render the buffer onto the screen
      wipeDisplay();
      if (buffer[0] == U'\0') { // If string empty...
        return; // Do nothing else, return
      }
      if (strlen32(buffer) <= bufferPos) { displayPos = 0; bufferPos = 0; } // If all characters in the buffer have been rendered, cycle back to the first
      if (buffer[bufferPos] == U'.') { bufferPos++; } // If the current character is a decimal, simply move on to the next
      uint8_t digitPos = (displayPos + (digitsClass - filterDecimals(buffer)));
      digitalWrite(digitPinsClass[digitPos], digitOn); // Right align the text on the display
      for (uint8_t i = 0; i < digitsClass; i++) { if (i != (digitPos)) { digitalWrite(digitPinsClass[i], digitOff); } } // Turn off all digits besides the current one
      if (strlen32(buffer) > bufferPos && buffer[bufferPos + 1] == U'.') { digitalWrite(segmentPinsClass[14], segmentOn); } // Turn on this digit's DP if the next character is a decimal

      bool charFound = false; // A boolean flag that tracks whether the requested character has been found in the selected font
      bool qmarkFound = false; // A boolean flag that tracks whether a '?' has been found in the selected font. This is displayed if charFound == false
      uint16_t bitmap = 0b00000000000000; // Stores the bitmap for the desired character
      uint16_t qmark_btmp = 0b00000000000000; // Stores the bitmap for an unknown character / question mark

      for (uint16_t i = 0; currentFont[i].identifier != 0; i++) { // Search through the font for the desired character
        if (currentFont[i].identifier == U'?') { qmarkFound = true; qmark_btmp = currentFont[i].bitmap; } // Save the question mark bitmap, if found
        if (currentFont[i].identifier == buffer[bufferPos]) { charFound = true; bitmap = currentFont[i].bitmap; break; } // If the requsted character is found, save it and stop searching
      }

      if (!charFound) { // If the requested character could not be located in the current font...
        if (qmarkFound) { // Check if a question mark is available
          bitmap = qmark_btmp; // If so, log this as the bitmap for display
        }else{
          bitmap = 0b00000000000000; // Else, do not display anything
        }
      }

      // Read the bitmap and write to the segments
      for (int8_t i = 13; i >= 0; i--) {
        digitalWrite(segmentPinsClass[13 - i], bitRead(bitmap, i) ? segmentOn : segmentOff);
      }

      displayPos++; bufferPos++; // Move on to the next chcaracter when the next call occurs
    }

AutoPlex14* AutoPlex14::displays[MAX_DISPLAYS] = { nullptr };
static bool AutoPlex14::timerConfigured = false;

ISR(TIMER1_COMPA_vect) {
      for (uint8_t i = 0; i < _displayIndex; i++) {
        AutoPlex14::displays[i]->multiplex();
      }
}
