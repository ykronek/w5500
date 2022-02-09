#include <Arduino.h>
#include "MgsModbus.h"
#include <SPI.h>
#include <Wire.h>

MgsModbus Mb;

unsigned long myTimer;

void setup()
{
  uint8_t mac[] = {0x90, 0xA2, 0xDA, 0x00, 0x51, 0x06};
  uint8_t ip[] = {192, 168, 1, 177};
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
  Serial.println(Ethernet.localIP());
}

void loop()
{
  Mb.MbsRun();

  if (millis() - myTimer >= 1000)
  {
    myTimer = millis();
    Mb.MbData[0] = random(1, 100);
    Mb.MbData[1] = random(100, 200);
    Mb.MbData[2] = random(200, 300);
    Mb.MbData[3] = random(300, 400);
    Mb.MbData[4] = random(400, 500);
    Mb.MbData[5] = random(500, 600);
    Mb.MbData[6] = random(600, 700);
    Mb.MbData[7] = random(700, 800);
    Mb.MbData[8] = random(800, 900);
    Mb.MbData[9] = random(900, 1000);
    Serial.println(Mb.MbData[0]);
  }
}