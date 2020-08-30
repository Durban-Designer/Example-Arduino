/*
  Constants.h - header for returning constants.
  Copywrite Royce Birnbaum 2020
*/

#ifndef Constants_h
#define Constants_h

#include "Arduino.h"

// setup wifi
const char *ssid = "";
const char *password = "";
// set host to be the CEAD Hub (this can be any address)
const char *host = "http://192.168.1.24:3000/";
const String dns = "neuronautsensor";
const byte dnsPort = 53;
// the frequency used for serial communication
const int baudRate = 9600;
// certificates TODO move somewhere secure and replace with non self signed
// to create certs do the following after installing openssl
// $ openssl
// $ genrsa -out key.txt 1024
// $ rsa -in key.txt -out key.txt
// $ req -sha256 -new -nodes -key key.txt -out cert.csr
// $ x509 -req -sha256 -days 365 -in cert.csr -signkey key.txt -out cert.txt
// $ exit
// NEVER PUSH KEYS TO SOURCE CONTROL!!!
// We will need to devise a method of autogenerating certs, inserting into code, flashing microcontrollers, and ejecting with one script. Should be possible with Arduino CLI.
static const char serverCert[] PROGMEM = R"EOF(

)EOF";

static const char serverKey[] PROGMEM = R"EOF(

)EOF";

#endif
