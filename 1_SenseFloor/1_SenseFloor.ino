/*
  Title: SenseFloor
  Authors: Joyce den Hertog, Ilse Driessen, Zoë Breed

  Needed:
  - 6 DMX lamps, connected in a series to digital pin 3.
  - 1 temperature sensor, connected to analogue pin 0.
  - 1 sound sensor, connected to digital pin 8.

  How it works:
  -> When you make sound with your voice the lamps of the dancefloor will change brightness
   depending on the loudness of your voice.
  -> When your body temperature increases, the color combination of the dancefloor changes.

  Have fun!
*/

#include <DmxSimple.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// define pins
const int soundPin = 8;
const int DMXPin = 3;
int tempPin = 0;

int numberOfLamps = 6;

// variables for measuring the sound in samples of 100 ms long.
const int soundSampleTime = 100;
unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;
int soundValue = 0;
int maxSoundValue = 3500;

// variables for measuring temperature
float temp, volt, reading;

void setup() {
  Serial.begin(9600);
  DmxSimple.usePin(DMXPin);
  DmxSimple.maxChannel(4); // RGBW
}

void loop() {
  millisCurrent = millis();
  millisElapsed = millisCurrent - millisLast;

  if (digitalRead(soundPin) == HIGH) {
    if (soundValue < maxSoundValue) {
      soundValue++;
    }
  }

  if (millisElapsed > soundSampleTime) {

    // formula from here: https://learn.adafruit.com/tmp36-temperature-sensor/using-a-temp-sensor
    reading = analogRead(tempPin);
    volt = reading * 5.0;
    volt /= 1024.0;
    temp = (volt - 0.5) * 100 ;

    Serial.println(temp);
    if (temp <= 25) {
      lampColors(1);
    } else if (temp > 26 && temp <= 27) {
      lampColors(2);
    } else if (temp > 27 && temp <= 28 ) {
      lampColors(3);
    } else if (temp > 28 ) {
      lampColors(4);
    }
    soundValue = 0;
    millisLast = millisCurrent;
  }
}
