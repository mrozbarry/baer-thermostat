#include "./Button.h"
#include "./Sensor.h"
#include "./LCD.h"

#ifndef UTILS_STATE_H
#define UTILS_STATE_H 1

class Buttons {
public:
  Buttons();
  ~Buttons();

  Button up;
  Button down;
  Button left;
  Button right;
  Button select;
};

class State {
public:
  State();

  void tick(unsigned long now);

  unsigned long now;

  Sensor outdoorTemp;
  Sensor indoorTemp;

  LCD lcd;

  Buttons buttons;
};

#endif

