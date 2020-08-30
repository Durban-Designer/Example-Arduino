/*
  WebServerController.h - Class for managing web server.
  Copywrite Royce Birnbaum 2020
*/

#ifndef WebServerController_h
#define WebServerController_h

#include <ESP8266WebServer.h>
#include <ESP8266WebServerSecure.h>
#include "Arduino.h"
#include "../WebServerHandler/WebServerHandler.h"

class WebServerController
{
public:
  static void setupWebServer();
  static void webServerLoop();
};

#endif
