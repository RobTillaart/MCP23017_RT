#pragma once
//
//    FILE: MCP23017.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.4.0
// PURPOSE: Arduino library for I2C MCP23017 16 channel port expander
//    DATE: 2019-10-12
//     URL: https://github.com/RobTillaart/MCP23017_RT


// WARNING: please read REV D note in readme.md.


#include "Arduino.h"
#include "Wire.h"


#define MCP23017_LIB_VERSION              (F("0.4.0"))

#define MCP23017_OK                       0x00
#define MCP23017_PIN_ERROR                0x81
#define MCP23017_I2C_ERROR                0x82
#define MCP23017_VALUE_ERROR              0x83
#define MCP23017_PORT_ERROR               0x84


#define MCP23017_INVALID_READ             -100


class MCP23017
{
public:
  MCP23017(uint8_t address, TwoWire *wire = &Wire);

#if defined(ESP8266) || defined(ESP32)
  bool    begin(const uint8_t dataPin, const uint8_t clockPin);
#endif
  bool    begin();
  bool    isConnected();


  //      single pin interface
  //      mode = INPUT, OUTPUT or INPUT_PULLUP (==INPUT)
  bool    pinMode(uint8_t pin, uint8_t mode);
  bool    digitalWrite(uint8_t pin, uint8_t value);
  uint8_t digitalRead(uint8_t pin);

  bool    setPolarity(uint8_t pin, bool reversed);
  bool    getPolarity(uint8_t pin, bool &reversed);
  bool    setPullup(uint8_t pin, bool pullup);
  bool    getPullup(uint8_t pin, bool &pullup);


  //      8 pins interface
  //      port  = 0..1
  //      value = bit pattern
  bool    pinMode8(uint8_t port, uint8_t value);
  bool    write8(uint8_t port, uint8_t value);
  int     read8(uint8_t port);

  bool    setPolarity8(uint8_t port, uint8_t mask);
  bool    getPolarity8(uint8_t port, uint8_t &mask);
  bool    setPullup8(uint8_t port, uint8_t mask);
  bool    getPullup8(uint8_t port, uint8_t &mask);


  //       16 pins interface
  //       value = bit pattern
  bool     pinMode16(uint16_t value);
  bool     write16(uint16_t value);
  uint16_t read16();

  bool     setPolarity16(uint16_t mask);
  bool     getPolarity16(uint16_t &mask);
  bool     setPullup16(uint16_t mask);
  bool     getPullup16(uint16_t &mask);

  int      lastError();

private:
  bool    writeReg(uint8_t reg, uint8_t value);
  uint8_t readReg(uint8_t reg);

  uint8_t   _address;
  TwoWire*  _wire;
  uint8_t   _error;
};


// -- END OF FILE --

