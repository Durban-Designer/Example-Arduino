/*
  WebServerHandler.h - Class for handling web server requests.
  Copywrite Royce Birnbaum 2020
*/

#ifndef WebServerHandler_h
#define WebServerHandler_h

#include <ESP8266WebServer.h>
#include <ESP8266WebServerSecure.h>
#include "Arduino.h"
#include "../Validator/Validator.h"
#include "../ErrorMessages.h"

class WebServerHandler
{
public:
  static void secureRedirect();
  static void handleGet();
  static void handleCaptureSensors();
  static void handleCaptureLed();
  static void handleDistributeLed();
  static void handleCaptureValves();
  static void handleDistributeValves();
  static void handleNotFound();
};

#endif
