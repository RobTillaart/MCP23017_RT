//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2021-01-01
// PURPOSE: unit tests for the MCP23017
//          https://github.com/RobTillaart/MCP23017_RT
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual);               // a == b
// assertNotEqual(unwanted, actual);            // a != b
// assertComparativeEquivalent(expected, actual);    // abs(a - b) == 0 or (!(a > b) && !(a < b))
// assertComparativeNotEquivalent(unwanted, actual); // abs(a - b) > 0  or ((a > b) || (a < b))
// assertLess(upperBound, actual);              // a < b
// assertMore(lowerBound, actual);              // a > b
// assertLessOrEqual(upperBound, actual);       // a <= b
// assertMoreOrEqual(lowerBound, actual);       // a >= b
// assertTrue(actual);
// assertFalse(actual);
// assertNull(actual);

// // special cases for floats
// assertEqualFloat(expected, actual, epsilon);    // fabs(a - b) <= epsilon
// assertNotEqualFloat(unwanted, actual, epsilon); // fabs(a - b) >= epsilon
// assertInfinity(actual);                         // isinf(a)
// assertNotInfinity(actual);                      // !isinf(a)
// assertNAN(arg);                                 // isnan(a)
// assertNotNAN(arg);                              // !isnan(a)

#include <ArduinoUnitTests.h>


#include "Arduino.h"
#include "MCP23017.h"


unittest_setup()
{
}

unittest_teardown()
{
}


// TODO more tests if godmode->wire works
unittest(test_constructor)
{
  Wire.resetMocks();

  fprintf(stderr, "VERSION: %s\n", MCP23017_LIB_VERSION);

  MCP23017 MCP(0x27);

  assertFalse(Wire.didBegin());
  MCP.begin();
  // in fact invalid ...
  assertTrue(Wire.didBegin());
  assertTrue(MCP.isConnected());

}


unittest(test_lastError)
{
  Wire.resetMocks();

  fprintf(stderr, "VERSION: %s\n", MCP23017_LIB_VERSION);

  MCP23017 MCP(0x27);
  MCP.begin();
  assertEqual(MCP23017_OK, mcp.lastError());
  
  // MCP23017_PIN_ERROR
  MCP.pinMode(16, INPUT);
  assertEqual(MCP23017_PIN_ERROR, mcp.lastError());
  assertEqual(MCP23017_OK, mcp.lastError());
  MCP.digitalWrite(16, 1);
  assertEqual(MCP23017_PIN_ERROR, mcp.lastError());
  assertEqual(MCP23017_OK, mcp.lastError());
  uint8_t y = MCP.digitalRead(16);
  assertEqual(MCP23017_PIN_ERROR, mcp.lastError());
  assertEqual(MCP23017_OK, mcp.lastError());


  // MCP23017_VALUE_ERROR  - 3 is not INPUT, INPUT_PULLUP, OUTPUT)
  MCP.pinMode(0, 3);
  assertEqual(MCP23017_VALUE_ERROR, mcp.lastError());
  assertEqual(MCP23017_OK, mcp.lastError());


  // MCP23017_PORT_ERROR
  MCP.pinMode8(2, 0xF0);
  assertEqual(MCP23017_PORT_ERROR, mcp.lastError());
  assertEqual(MCP23017_OK, mcp.lastError());
  MCP.write8(2, 0xF0);
  assertEqual(MCP23017_PORT_ERROR, mcp.lastError());
  assertEqual(MCP23017_OK, mcp.lastError());
  uint8_t x = MCP.read8(2);
  assertEqual(MCP23017_PORT_ERROR, mcp.lastError());
  assertEqual(MCP23017_OK, mcp.lastError());
}


unittest_main()

// --------
