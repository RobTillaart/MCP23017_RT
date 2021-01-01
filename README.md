
[![Arduino CI](https://github.com/RobTillaart/MCP23017_RT/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/MCP23017_RT/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/MCP23017_RT.svg?maxAge=3600)](https://github.com/RobTillaart/MCP23017_RT/releases)

# MCP23017_RT

Arduino library for I2C MCP23017 16 channel port expander

## Description

TODO

## Interface

### Constructor

- **MCP23017(address)** constructor
- **begin()** for UNO
- **begin(sda, scl)** for ESP32
- **isConnected()** returns true if connected, false otherwise

### single pin interface

- **pinMode(pin, value)**       pin = 0..16  value = INPUT,OUTPUT
- **digitalWrite(pin, value)**  pin = 0..16  value = LOW(0) HIGH (!0)
- **digitalRead(pin)**          pin = 0..16

### 8 pins interface

- **pinMode8(port, value)**     port = 0, 1  value = 
- **write8(port, value)**       port = 0, 1  value =
- **read8(port)**               port = 0, 1

## Operation

See examples

