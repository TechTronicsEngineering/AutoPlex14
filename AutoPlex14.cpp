#include "AutoPlex14.h"

font systemFont[] = { // A, B, C, D, E, F, G1, G2, H, J, K, L, M, N
  { U'0', 0b11111111111111 }, // Display test
  END
};
font defaultFont[] = { // A, B, C, D, E, F, G1, G2, H, J, K, L, M, N
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

void AutoPlex14::wipeDisplay() { // Used internally to turn the display off without clearing the buffer
      for (uint8_t i = 0; i < digitsClass; i++) { digitalWrite(digitPinsClass[i], digitOff); }
      for (uint8_t i = 0; i < 15; i++) { digitalWrite(segmentPinsClass[i], segmentOff); }
}

void AutoPlex14::begin(uint8_t displayType, uint8_t digits, uint8_t digitPins[], uint8_t segmentPins[], bool multiplexing = AUTOPLEX) {
      // Decide based on the type of display what "on" represents
      switch (displayType) {
        case COMMON_ANODE: segmentOn = LOW; digitOn = HIGH; break;
        case COMMON_CATHODE: segmentOn = HIGH; digitOn = LOW; break;
        case CAWDDT: segmentOn = LOW; digitOn = LOW; break;
        case CCWDDT: segmentOn = HIGH; digitOn = HIGH; break;
      }
      // Define "off" as the inverse of "on"
      segmentOff = !segmentOn;
      digitOff = !digitOn;

      digitsClass = digits; // Store the number of digits on the display inside the class
      for (uint8_t i = 0; i < digitsClass; i++) { digitPinsClass[i] = digitPins[i]; } // Save digit pins to the class
      for (uint8_t i = 0; i < 15; i++) { segmentPinsClass[i] = segmentPins[i]; } // Save segment pins to class

      if (multiplexing == AUTOPLEX) { // Check if multiplexing should be performed automatically
        manualplexing = false;
        noInterrupts();
        displays[_displayIndex++] = this; // Register new display instance
        // Configure Timer1 for multiplexing at ~1kHz
        TCCR1A = 0;
        TCCR1B = 0;
        TCNT1  = 0;
        OCR1A = 249;
        TCCR1B |= (1 << WGM12);
        TCCR1B |= (1 << CS11) | (1 << CS10);
        TIMSK1 |= (1 << OCIE1A);
        interrupts();
      }else{
        manualplexing = true;
      }

      // Configure display pins as outputs
      for (uint8_t i = 0; i < digitsClass; i++) { pinMode(digitPinsClass[i], OUTPUT); }
      for (uint8_t i = 0; i < 15; i++) { pinMode(segmentPinsClass[i], OUTPUT); }

      clear(); // Ensure display is blank
}

void AutoPlex14::clear() { // Empty the display buffer and deactivate all digits and segments
      noInterrupts();
      buffer[0] = U'\0';
      interrupts();
      wipeDisplay();
}

void AutoPlex14::setFont(font* newFont) {
      noInterrupts();
      currentFont = newFont;
      interrupts();
}

void AutoPlex14::print(const char32_t* text) { // Shows a string on the display; works with any Unicode character the selected font defines
      noInterrupts();
      if (strlen32(text) > (MAX_DIGITS * 2) - 1) { buffer[0] = U'\0'; } else { strcpy32(buffer, text); }
      interrupts();
}

void AutoPlex14::print(const char* text) { // Shows a string on the display; only works with ASCII characters
      noInterrupts();
      if (strlen(text) <= (MAX_DIGITS * 2) - 1) { strcpy8to32(buffer, text); }
      interrupts();
}

void AutoPlex14::print(int32_t num) { // Set the fourteen segment display's buffer to an integer
      noInterrupts();
      char temporary[11];
      itoa(num, temporary, 10);
      if (strlen(temporary) > (MAX_DIGITS * 2) - 1) { buffer[0] = U'\0'; } else { strcpy8to32(buffer, temporary); }
      interrupts();
}

void AutoPlex14::print(double num, uint8_t decimalPlaces) { // Set the fourteen segment display's buffer to a double/float
      noInterrupts();
      char temporary[11];
      dtostrf(num, 0, decimalPlaces, temporary);
      if (strlen(temporary) > (MAX_DIGITS * 2) - 1) { buffer[0] = U'\0'; } else { strcpy8to32(buffer, temporary); }
      interrupts();
}

void AutoPlex14::append(const char32_t* text) { // Add a 32-bit string suffix to the current display contents
      if (strlen32(buffer) + strlen32(text) > (MAX_DIGITS * 2) - 1) { return; } // Don't add suffix if the current contents + suffix contain more characters than the library supports
      noInterrupts();
      uint8_t i = 0;
      while (buffer[i] != U'\0') { i++; } // Find the number of indexes before termination
      for (uint8_t u = 0; text[u] != U'\0'; u++) { // Add the suffix
        buffer[i++] = text[u];
      }
      buffer[i] = U'\0'; // Terminate string
      interrupts();
}

void AutoPlex14::append(const char* text) { // Add an ASCII string suffix to the current display contents
      if (strlen32(buffer) + strlen(text) > (MAX_DIGITS * 2) - 1) { return; } // Don't add suffix if the current contents + suffix contain more characters than the library supports
      noInterrupts();
      uint8_t i = 0;
      while (buffer[i] != U'\0') { i++; } // Find the number of indexes before termination
      for (uint8_t u = 0; text[u] != U'\0'; u++) { // Add the suffix
        buffer[i++] = (char32_t)text[u];
      }
      buffer[i] = U'\0'; // Terminate string
      interrupts();
}

void AutoPlex14::append(int32_t num) { // Add an integer suffix to the current display contents
      char string8[11];
      itoa(num, string8, 10);
      char32_t string32[11];
      strcpy8to32(string32, string8);
      if (strlen32(buffer) + strlen32(string32) > (MAX_DIGITS * 2) - 1) { return; } // Don't add suffix if the current contents + suffix contain more characters than the library supports
      noInterrupts();
      uint8_t i = 0;
      while (buffer[i] != U'\0') { i++; } // Find the number of indexes before termination
      for (uint8_t u = 0; string32[u] != U'\0'; u++) { // Add the suffix
        buffer[i++] = string32[u];
      }
      buffer[i] = U'\0'; // Terminate string
      interrupts();
    }

void AutoPlex14::append(double num, uint8_t decimalPlaces) { // Add a double suffix to the current display contents
      char string8[11];
      dtostrf(num, 0, decimalPlaces, string8);
      char32_t string32[11];
      strcpy8to32(string32, string8);

      if (strlen32(buffer) + strlen32(string32) > (MAX_DIGITS * 2) - 1) { return; } // Don't add suffix if the current contents + suffix contain more characters than the library supports
      noInterrupts();
      uint8_t i = 0;
      while (buffer[i] != U'\0') { i++; } // Find the number of indexes before termination
      for (uint8_t u = 0; string32[u] != U'\0'; u++) { // Add the suffix
        buffer[i++] = string32[u];
      }
      buffer[i] = U'\0'; // Terminate string
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
      if (buffer[0] == U'\0') { // If string empty...
        wipeDisplay(); // Disable all digits and segments on the display
        return; // Do nothing else, return
      }
      if (currentDigit >= strlen32(buffer)) { currentDigit = 0; displayPosition = 0; } // Return to the start of the string when the end is reached
      wipeDisplay(); // Ensure display is blank before rendering a character
      if (buffer[currentDigit] == U'.') { currentDigit++; return; } // If current character is a decimal, simply move on
      digitalWrite(digitPinsClass[(displayPosition + (digitsClass - filterDecimals(buffer)))], digitOn); // Right align the text on the display
      for(uint8_t i = 0; i < digitsClass; i++){if(i != (displayPosition + (digitsClass - filterDecimals(buffer)))){digitalWrite(digitPinsClass[i], digitOff);}}

      bool charFound = false;
      bool qmarkFound = false;
      uint16_t bitmap = 0b00000000000000;
      uint16_t qmark_btmp = 0b00000000000000;

      for (uint16_t i = 0; currentFont[i].identifier != 0; i++) {
        if (currentFont[i].identifier == U'?') { qmarkFound = true; qmark_btmp = currentFont[i].bitmap; }
        if (currentFont[i].identifier == buffer[currentDigit]) { charFound = true; bitmap = currentFont[i].bitmap; break; }
      }

      if (!charFound) {
        if (qmarkFound) {
          bitmap = qmark_btmp;
        }else{
          bitmap = 0b00000000000000;
        }
      }

      for (int8_t i = 14 /*segments*/ - 1; i >= 0; i--) {
        digitalWrite(segmentPinsClass[map(i, 0, 13, 13, 0)], bitRead(bitmap, i) ? segmentOn : segmentOff);
      }

      if (currentDigit + 1 < strlen32(buffer) && buffer[currentDigit + 1] == U'.') { digitalWrite(segmentPinsClass[14], segmentOn); } // If next character is a decimal, activate the DP on this digit
      displayPosition++; // Increase the counter that corresponds to physical display position
      if (currentDigit <= strlen32(buffer)) { currentDigit++; } // Move on to the next digit when the next cycle is reached
}

AutoPlex14* AutoPlex14::displays[MAX_DISPLAYS] = { nullptr };

ISR(TIMER1_COMPA_vect) {
      for (uint8_t i = 0; i < _displayIndex; i++) {
        AutoPlex14::displays[i]->multiplex();
      }
}
