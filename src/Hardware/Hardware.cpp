/*
  Hardware.cpp - Class for managing and abstracting hardware connections.
  Copywrite Royce Birnbaum 2020
*/

#include "Arduino.h"
#include "Hardware.h"
#include "ArduinoJson.h"
#include "./Led/Led.h"

Led leds[4] = {
    Led(4, "red", true),
    Led(14, "green", true),
    Led(16, "blue", false),
    Led(2, "internal", false)};

String Hardware::handleGetLedData(String color)
{
  int found = -1;
  for (byte i = 0; i < 4; i = i + 1)
  {
    if (leds[i].getColor() == color)
    {
      found = i;
      break;
    }
  }
  if (found != -1)
  {
    return leds[found].toJson();
  }
  else
  {
    return "404";
  }
}

String Hardware::handleEnergizeLedAction(StaticJsonDocument<200> doc)
{
  String energized = doc["energized"];
  String color = doc["color"];
  int found = -1;
  for (byte i = 0; i < 4; i = i + 1)
  {
    if (leds[i].getColor() == doc["color"])
    {
      found = i;
      break;
    }
  }
  if (found != -1)
  {
    if ("true" == doc["energized"])
    {
      leds[found].energize();
    }
    else
    {
      leds[found].deEnergize();
    }
    return leds[found].toJson();
  }
  else
  {
    return "404";
  }
}

String Hardware::handleFlashLedAction(StaticJsonDocument<200> doc)
{
  int found = -1;
  for (byte i = 0; i < 4; i = i + 1)
  {
    if (leds[i].getColor() == doc["color"])
    {
      found = i;
      break;
    }
  }
  if (found != -1)
  {
    leds[found].flash(doc["iterations"]);
    return leds[found].toJson();
  }
  else
  {
    return "404";
  }
}