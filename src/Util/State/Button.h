typedef enum {
  UNKNOWN,
  PRESS,
  LONG_PRESS,
} PressType

class Button {
public:
  Button(int pin);

  void update(uint32 now);

  bool isPressed();
  uint32 pressDuration(uint32 now);

  bool wasReleasedThisFrame();
  bool wasPressed();
  bool wasLongPressed();


private:
  int pin;
  bool pressed;
  bool releasedThisFrame;
  PressType lastPress;
  uint8 lastPressedAt;
}

