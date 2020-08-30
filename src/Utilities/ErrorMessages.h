/*
  ErrorMessages.h - header for returning error messages.
  Copywrite Royce Birnbaum 2020
*/

#ifndef ErrorMessages_h
#define ErrorMessages_h

#include "Arduino.h"

const String homeMessage = "Welcome to the NeuroNaut Garden Sensor, I am still healthy!";
const String notFound = "404";
const String RouteNotFoundMessage = "{\"error\": \"404 route not found, please check the docs for supported routes!\"}";
const String DeserializationErrorMessage = "{\"error\": \"500 error deserializing provided json object, please ensure you are using JSON content type and formating.\"}";
const String BadRequestErrorMessageCaptureLed = "{\"error\": \"400 bad request body, ensure you provided the \'color\' key in the request body!\"}";
const String BadRequestErrorMessageDistributeLed = "{\"error\": \"400 bad request body, ensure you provided the \'action\', \'color\', and either \'energized\' or \'iterations\' key in the request body!\"}";
const String LedNotFoundMessage = "{\"error\": \"404 LED not found by color\"}";
const String ActionNotFoundMessageLed = "{\"error\": \"404 Action not found, available LED actions are \'energize\' and \'flash\'.\"}";
const String BadRequestErrorMessageCaptureValves = "{\"error\": \"400 bad request body, ensure you provided the \'location\' key in the request body!\"}";
const String BadRequestErrorMessageDistributeValve = "{\"error\": \"400 bad request body, ensure you provided the \'action\', \'location\', and either \'energized\' or \'energizeForTimeout\' key in the request body!\"}";
const String ValveNotFoundMessage = "{\"error\": \"404 valve not found by location\"}";
const String ActionNotFoundMessageValve = "{\"error\": \"404 Action not found, available LED actions are \'energize\' and \'flash\'.\"}";

#endif
