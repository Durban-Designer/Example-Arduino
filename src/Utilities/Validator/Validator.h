/*
  Validator.h - Library for validating Json inputs to the Web Server.
  Copywrite Royce Birnbaum 2020
*/

#ifndef Validator_h
#define Validator_h

#include "Arduino.h"
#include "ArduinoJson.h"

class Validator
{
public:
  static bool validateCaptureLed(StaticJsonDocument<200> doc);
  static bool validateDistributeLed(StaticJsonDocument<200> doc);
  static bool validateCaptureValves(StaticJsonDocument<200> doc);
  static bool validateDistributeValves(StaticJsonDocument<200> doc);
};

#endif
