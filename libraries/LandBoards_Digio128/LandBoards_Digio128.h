#ifndef LandBoards_digio128_h
#define LandBoards_digio128_h

////////////////////////////////////////////////////////////////////////////
//  landboards_digio128.h - Library for Land Boards DigIO-128 card
//  Created by Douglas Gilliland. 2015-11-23
//  Digio-128 is a card which has 8 of MCP23017 16-bit port expanders
//	Communication with the card is via I2C Two-wire interface
//  This library allows for both bit access and chip access to the card
//  	Bit access (128 bits) via digitalWrite, digitalRead, pinMode
//		Chip access (16-bits) via writeGPIOAB, readGPIOAB
//  Webpage for the card is at:
//	http://land-boards.com/blwiki/index.php?title=DIGIO-128
////////////////////////////////////////////////////////////////////////////
// Card has 8x MCP23017 chips
////////////////////////////////////////////////////////////////////////////

#include <inttypes.h>
#include <Arduino.h>
#include "Adafruit_MCP23017.h"

////////////////////////////////////////////////////////////////////////////////////
// enums follow
////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
// I2C Ports
//	MCP23017 0x20-0x27
////////////////////////////////////////////////////////////////////////////

class Digio128
{
  public:
    Digio128(void);
	void begin();
	void digitalWrite(uint8_t,uint8_t);		// Writes to a single bit
	uint8_t digitalRead(uint8_t);			// Reads a single bit
	void pinMode(uint8_t,uint8_t);			// Set the single bit direction (INPUT, INPUT_PULLUP, OUTPUT)
	void writeGPIOAB(uint8_t,uint16_t);		// Write to a 16-bit chip
	uint16_t readGPIOAB(uint8_t);			// Read from a 16-bit chip
  private:
	Adafruit_MCP23017 mcp0;
	Adafruit_MCP23017 mcp1;
	Adafruit_MCP23017 mcp2;
	Adafruit_MCP23017 mcp3;
	Adafruit_MCP23017 mcp4;
	Adafruit_MCP23017 mcp5;
	Adafruit_MCP23017 mcp6;
	Adafruit_MCP23017 mcp7;
};

#endif
