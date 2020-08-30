/*
  Led.cpp - Library for flashing Leds.
  Copywrite Royce Birnbaum 2020
*/

#include "Arduino.h"
#include "Validator.h"
#include "ArduinoJson.h"

bool Validator::validateCaptureLed(StaticJsonDocument<200> doc)
{
  String color = doc["color"];
  if (color.length() <= 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Validator::validateDistributeLed(StaticJsonDocument<200> doc)
{
  String action = doc["action"];
  String color = doc["color"];
  String energized = doc["energized"];
  String iterations = doc["iterations"];
  String energize = "energize";
  String flash = "flash";
  if (action.length() <= 0 || color.length() <= 0)
  {
    return true;
  }
  else if (energize == action)
  {
    if (energized.length() <= 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (flash == action)
  {
    if (iterations.length() <= 0)
    {
      return true;
    }
    else
    {
      return true;
    }
  }
  else
  {
    return true;
  }
}