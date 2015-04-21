// include these three libraries for all M3T3 projects
#include <spi4teensy3.h>
#include <EEPROM.h>
#include <M3T3.h>

float k = 5.2; // spring stiffness
float m = 1.0; // mass
float d = 8.0; // damping coefficient

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
  long tick_now = millis();
  long dt = tick_now - tick;
  
  if (dt >= 20) {
    
    int current_pos = analogRead(A1);
    
    int diff_center = (512 - current_pos);
    
    f = k * (diff_center - x) - (d * v);
    v += (f / m) * dt;
    x += v * dt;
    
    tick = millis();
    
    MotorA.torque(f);
  }

}
