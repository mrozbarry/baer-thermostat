#include "./Sensor.h"

Sensor::Sensor(int pin)
  : lastReadAt(0)
  , value(0.0f)
{
  this->pin = pin;
}

Sensor::~Sensor()
{}

float Sensor::read(unsigned long now)
{
  unsigned long diff = now - this->lastReadAt;
  if (diff < 1000) {
    return this->value;
  }

  this->lastReadAt = now;
  this->value = 0.0f; // Replace with call to GPIO stuff

  return this->value;
}
