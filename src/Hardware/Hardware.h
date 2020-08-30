/*
  Hardware.h - Class for managing and abstracting hardware connections.
  Copywrite Royce Birnbaum 2020
*/

#ifndef Hardware_h
#define Hardware_h

#include "Arduino.h"
#include "ArduinoJson.h"
#include "./Led/Led.h"

class Hardware
{
public:
  Led getLeds();
  String handleGetLedData(String color);
  String handleEnergizeLedAction(StaticJsonDocument<200> doc);
  String handleFlashLedAction(StaticJsonDocument<200> doc);
};

#endif
