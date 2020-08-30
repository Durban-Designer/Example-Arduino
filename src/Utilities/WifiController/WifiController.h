/*
  WifiController.h - WiFi setup class for the CEAD Sensor
  Copywrite Royce Birnbaum 2020
*/

#ifndef Wifi_h
#define Wifi_h

#include "Arduino.h"
#include <ESP8266WiFi.h>

class WifiController
{
public:
  static void setupWifi();
};

#endif
