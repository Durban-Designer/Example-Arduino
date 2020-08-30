/*
  WebServerHandler.cpp - Class for handling web server requests.
  Copywrite Royce Birnbaum 2020
*/

#include <ESP8266WebServer.h>
#include <ESP8266WebServerSecure.h>
#include "Arduino.h"
#include "WebServerHandler.h"
#include "../../Hardware/Hardware.h"
#include "../Validator/Validator.h"
#include "../ErrorMessages.h"

// setup web servers on ports
extern ESP8266WebServerSecure server;
extern ESP8266WebServer serverHTTP;
extern Hardware sensor;

// define endpoint handlers
void WebServerHandler::secureRedirect()
{
  String uri = "https://192.168.1.7" + serverHTTP.uri();
  serverHTTP.sendHeader("Location", uri, true);
  serverHTTP.send(307, "text/plain", "");
}

void WebServerHandler::handleGet()
{
  StaticJsonDocument<200> doc;
  String response;
  doc["message"] = homeMessage;
  serializeJsonPretty(doc, response);
  server.send(200, "application/json", response);
}

void WebServerHandler::handleCaptureLed()
{
  StaticJsonDocument<200> doc;
  DeserializationError err = deserializeJson(doc, server.arg("plain"));
  if (err)
  {
    server.send(500, "application/json", DeserializationErrorMessage);
  }
  else if (Validator::validateCaptureLed(doc))
  {
    server.send(400, "application/json", BadRequestErrorMessageCaptureLed);
  }
  else
  {
    String response = sensor.handleGetLedData(doc["color"]);
    if (notFound == response)
    {
      server.send(404, "application/json", LedNotFoundMessage);
    }
    else
    {
      server.send(200, "application/json", response);
    }
  }
}

void WebServerHandler::handleDistributeLed()
{
  StaticJsonDocument<200> doc;
  DeserializationError err = deserializeJson(doc, server.arg("plain"));
  if (err)
  {
    server.send(500, "application/json", DeserializationErrorMessage);
  }
  else if (Validator::validateDistributeLed(doc))
  {
    server.send(400, "application/json", BadRequestErrorMessageDistributeLed);
  }
  else
  {
    if ("energize" == doc["action"])
    {
      String response = sensor.handleEnergizeLedAction(doc);
      if (notFound == response)
      {
        server.send(404, "application/json", LedNotFoundMessage);
      }
      else
      {
        server.send(200, "application/json", response);
      }
    }
    else if ("flash" == doc["action"])
    {
      String response = sensor.handleFlashLedAction(doc);
      if (notFound == response)
      {
        server.send(404, "application/json", LedNotFoundMessage);
      }
      else
      {
        server.send(200, "application/json", response);
      }
    }
    else
    {
      server.send(404, "application/json", ActionNotFoundMessageLed);
    }
  }
}

void WebServerHandler::handleNotFound()
{
  Serial.println(server.uri());
  server.send(404, "application/json", RouteNotFoundMessage);
}
