#ifndef UTILS_STATE_BUTTON_H
#define UTILS_STATE_BUTTON_H  1

typedef enum {
  UNKNOWN,
  PRESS,
  LONG_PRESS
} PressType;

class Button {
public:
  Button(int pin);

  void onTick(unsigned long now);

  bool isPressed();
  unsigned long pressDuration(unsigned long now);

  bool wasReleasedThisFrame();
  bool wasPressed();
  bool wasLongPressed();


private:
  int pin;
  bool pressed;
  bool releasedThisFrame;
  PressType lastPress;
  unsigned long lastPressedAt;
};

#endif
