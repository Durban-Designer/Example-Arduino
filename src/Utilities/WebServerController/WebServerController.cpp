/*
  WebServerController.cpp - Class for managing web server.
  Copywrite Royce Birnbaum 2020
*/

#include <ESP8266WebServer.h>
#include <ESP8266WebServerSecure.h>
#include "Arduino.h"
#include "WebServerController.h"
#include "../WebServerHandler/WebServerHandler.h"

extern ESP8266WebServerSecure server;
extern ESP8266WebServer serverHTTP;

void WebServerController::setupWebServer()
{
  configTime(3 * 3600, 0, "pool.ntp.org", "time.nist.gov");
  // define http redirect to https
  serverHTTP.onNotFound(WebServerHandler::secureRedirect);
  serverHTTP.begin();
  // define is alive route handling
  server.on("/", WebServerHandler::handleGet);
  // define /leds route handling
  server.on("/leds/capture", HTTP_POST, WebServerHandler::handleCaptureLed);
  server.on("/leds/distribute", HTTP_POST, WebServerHandler::handleDistributeLed);
  // define fallback route
  server.onNotFound(WebServerHandler::handleNotFound);
  // Start the server
  server.begin();
  Serial.println("Server listening");
}

void WebServerController::webServerLoop()
{
  serverHTTP.handleClient();
  server.handleClient();
}
