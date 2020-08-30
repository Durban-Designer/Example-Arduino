/*
  WifiController.cpp - WiFi setup class for the CEAD Sensor
  Copywrite Royce Birnbaum 2020
*/

#include "Arduino.h"
#include <ESP8266WiFi.h>
#include "WifiController.h"

extern char *ssid;
extern char *password;

void WifiController::setupWifi()
{
  Serial.println();
  WiFi.begin(ssid, password);

  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}
