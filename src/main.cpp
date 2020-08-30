/*
  main.cpp - Main execution file for the CEAD Sensor unit
  Copywrite Royce Birnbaum 2020
*/

#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESP8266WebServer.h>
#include <ESP8266WebServerSecure.h>
#include "./Utilities/Constants.h"
#include "./Hardware/Hardware.h"
#include "./Utilities/WifiController/WifiController.h"
#include "./Utilities/WebServerController/WebServerController.h"

// setup web servers on ports
ESP8266WebServer serverHTTP(80);
BearSSL::ESP8266WebServerSecure server(443);

// instantiate needed objects
Hardware sensor;
// TODO setup security for payload level encyption

// setup method automatically runs when the chip is powered on
void setup()
{
  Serial.begin(baudRate);
  delay(10);
  WifiController::setupWifi();
  // todo register with base unit on launch
  server.getServer().setRSACert(new BearSSL::X509List(serverCert), new BearSSL::PrivateKey(serverKey));
  WebServerController::setupWebServer();
}

// the loop automatically runs forever and ever after setup
void loop()
{
  WebServerController::webServerLoop();
}