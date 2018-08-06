////////////////////////////////////////////////////////////////////////////
//  OneWireLogger.h - Library for OneWireLogger Shield
//  Created by Douglas Gilliland. 2012-07-27
////////////////////////////////////////////////////////////////////////////
// Pin assignments as referenced to the OneWireLogger Board
// 
////////////////////////////////////////////////////////////////////////////

#ifndef LANDBOARDS_ONEWIRELOGGER_h
#define LANDBOARDS_ONEWIRELOGGER_h

#include "Arduino.h"

////////////////////////////////////////////////////////////////////////////////////
// enums follow
////////////////////////////////////////////////////////////////////////////////////

enum KEY_PRESSES
{
  NONE,
  RIGHT,
  UP,
  DOWN,
  LEFT,
  SELECT,
};

////////////////////////////////////////////////////////////////////////////
// I/O Pins on the Arduino UNO as used by the One Wire Data Logger Board
// Ports/Leo Functions/Connections
// PF0(ADC0) = Analog Input 5 = SW5WAY
// PC7 = Digital 13 = Backlight
// PB7 = Digital 11 = SDCS - SD Card Chip Select
// PB6 = Digital 10 = LCDRST - LCD Reset
// PB5 = Digital 9 = LCDCS - LCD Chip Select
// PB4 = Digital 8 = LCDRS - LCD Register Select
// PB3 = MISO
// PB2 = MOSI
// PB1 = SCK
// PD7 = Digital 6 = ONE-WIRE
// PD5 = Leo? = PWR-OFF
// PD1 =  = SDA - To RTC
// PD0 =  = SCLK - To RTC
////////////////////////////////////////////////////////////////////////////

#define ONE_WIRE    6
#define LCD_DC      8 
#define LCD_CS      9
#define LCD_RST     10
#define SD_CS       11
#define BACKLIGHT   13
#define KEYPAD      A5
#define PWROFF      PD5

#define LCD_ROWS 16
#define LCD_COLUMNS 21

// #define SDATA       A4
// #define SDCLK       A5

class LandBoards_OneWireLogger
{
  public:
    LandBoards_OneWireLogger(void);
    uint8_t pollKeypad(void);
    void waitForKeyRelease(void);
    uint8_t getKeyPressed(void);
    uint8_t waitKeyPressed(void);
    uint8_t delayAvailable(int delayTime);
  private:
    void initPins(void);
};

#endif
