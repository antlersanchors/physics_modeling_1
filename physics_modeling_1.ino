// include these three libraries for all M3T3 projects
#include <spi4teensy3.h>
#include <EEPROM.h>
#include <M3T3.h>

float k = 0; // spring stiffness
float m = 0; // mass
float d = 0; // damping coefficient

float x = 0; // (virtual) position
float v = 0; // velocity
float f = 0; // force (f = ma)

long tick = 0;
int last_pos = 0;

int c = 0;

void setup() {
  tick = millis();
  last_pos = analogRead(A1);
  x = last_pos;

}

void loop() {
  

}
