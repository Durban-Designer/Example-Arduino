/*
  Led.h - Library for flashing Leds.
  Copywrite Royce Birnbaum 2020
*/

#ifndef Led_h
#define Led_h

#include "Arduino.h"
#include "ArduinoJson.h"

class Led
{
public:
  Led(
      int pin,
      String color,
      bool energizedVal);
  int getPin();
  bool getEnergizedStatus();
  String getColor();
  void energize();
  void deEnergize();
  void flash(byte iterations);
  String toJson();

private:
  int _pin;
  String _color;
  bool _energized;
  bool _energizedVal;
};

#endif
