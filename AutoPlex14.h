#ifndef AUTOPLEX14_H
#define AUTOPLEX14_H

#include <Arduino.h>

#define COMMON_ANODE 0
#define COMMON_CATHODE 1
#define CAWDDT 2 // Common Anode With Digit Drive Transistors
#define CCWDDT 3 // Common Cathode With Digit Drive Transistors
#define MAX_DIGITS 6 // Defines the maximum number of digits the library can support per display. You may increase this if you plan to use larger displays, at the cost of more memory usage
#define MAX_DISPLAYS 4 // Defines the maximum number of total individual displays the library can control simultaneously. May be increased at the price of more memory usage
#define AUTOPLEX 1 // Automatic interrupt-based multiplexing
#define MANUALPLEX 0 // Manual multiplexing flag

struct glyph {
  char32_t identifier;
  uint16_t bitmap;
};

#define font const glyph
#define END { 0, 0 }

extern font systemFont[];
extern font defaultFont[];

extern uint8_t _displayIndex;
class AutoPlex14 {
private:
    uint8_t digitsClass, digitPinsClass[MAX_DIGITS], segmentPinsClass[15];
    bool segmentOn, segmentOff, digitOn, digitOff;
    volatile uint8_t bufferPos = 0; // The character within the buffer which the multiplexing logic is currently reviewing
    volatile uint8_t displayPos = 0; // The physical position of the current character on the display
    static bool timerInitialized;
    char32_t buffer[(MAX_DIGITS * 2) + 1] = U""; // Buffer to hold the contents of the display. Enough space for MAX_DIGITS characters, decimal points, and a null termination
    font* currentFont = defaultFont;
    bool manualplexing = false;
    void wipeDisplay();
    size_t filterDecimals(const char32_t* string);
    size_t filterDecimals(const char* string);
    char32_t* strcpy8to32(char32_t* dest, const char* src);
    char32_t* strcpy32(char32_t* dest, const char32_t* src);
    size_t strlen32(const char32_t* string);
public:
    static AutoPlex14* displays[MAX_DISPLAYS];
    bool begin(uint8_t displayType, uint8_t digits, uint8_t digitPins[], uint8_t segmentPins[], bool multiplexing = AUTOPLEX);
    void testDisplay(unsigned long ms);
    void multiplex();
    void append(const char* text);
    void append(const char32_t* text);
    void append(int num);
    void append(double num, uint8_t decimalPlaces);
    void setFont(font* newFont);
    void clear();
    void print(const char* text);
    void print(const char32_t* text);
    void print(int num);
    void print(double num, uint8_t decimalPlaces);
    void print(double num);
};
ISR(TIMER1_COMPA_vect);

#endif
