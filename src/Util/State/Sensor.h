#ifndef UTILS_STATE_SENSOR_H
#define UTILS_STATE_SENSOR_H  1

class Sensor
{
public:
  /*
   * I'm making an assumption that we can read off a single pin, but this may need to change.
   * For now, it's just an int, but we'll need to look at your specs
   */
  Sensor(int pin);
  ~Sensor();

  float read(unsigned long now);

private:
  int     pin;
  unsigned long lastReadAt;
  float   value;
};

#endif
