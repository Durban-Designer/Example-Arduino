/*
  Led.cpp - Library for flashing Leds.
  Copywrite Royce Birnbaum 2020
*/

#include "Arduino.h"
#include "Led.h"
#include "ArduinoJson.h"

Led::Led(int pin, String color, bool energizedVal)
{
  pinMode(pin, OUTPUT);
  if (energizedVal)
  {
    digitalWrite(pin, LOW);
  }
  else
  {
    digitalWrite(pin, HIGH);
  }
  _pin = pin;
  _color = color;
  _energized = false;
  _energizedVal = energizedVal;
}

int Led::getPin()
{
  return _pin;
}

bool Led::getEnergizedStatus()
{
  return _energized;
}

String Led::getColor()
{
  return _color;
}

void Led::energize()
{
  if (_energizedVal)
  {
    digitalWrite(_pin, HIGH);
  }
  else
  {
    digitalWrite(_pin, LOW);
  }
  _energized = true;
}

void Led::deEnergize()
{
  if (_energizedVal)
  {
    digitalWrite(_pin, LOW);
  }
  else
  {
    digitalWrite(_pin, HIGH);
  }
  _energized = false;
}

void Led::flash(byte iterations)
{
  for (byte i = 0; i < iterations; i = i + 1)
  {
    Led::energize();
    delay(100);
    Led::deEnergize();
  }
}

String Led::toJson()
{
  StaticJsonDocument<200> doc;
  String response;
  doc["pin"] = _pin;
  doc["color"] = _color;
  doc["energized"] = _energized;
  serializeJsonPretty(doc, response);
  return response;
}
