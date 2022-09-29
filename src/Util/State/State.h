#ifndef UTILS_STATE_H
#define UTILS_STATE_H 1

#include "./Button.h"
#include "./Sensor.h"


typedef struct {
  Button up;
  Button down;
  Button left;
  Button right;
  Button select;
} Buttons;

class State {
public:
  State();

  void onTick(uint32 now);

  uint32 now;

  Sensor outdoorTemp;
  Sensor indoorTemp;

  LCD lcd;

  Buttons buttons;
}

#endif

