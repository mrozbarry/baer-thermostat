#include "./Button.h"

Button::Button(int pin)
  : state(UNKNOWN)
  , lastPressedAt(0)
  , pressedThisFrame(false)
{
  this->pin = pin;
}

void Button::update(uint32 now)
{
  bool prevPressed = this->pressed;
  this->releasedThisFrame = false;

  // Read pin state
  // set this->pressed to true|false
  
  if (prevPressed == pressed) {
    return;
  }

  if (pressed) {
    this->lastPressedAt = now;
    return;
  }

  this->releasedThisFrame = true;

  if (this->pressDuration(now) > 300) {
    this->lastPress = LONG_PRESS;
    return;
  } 

  this->lastPress = PRESS;
}

bool Button::isPressed()
{
  return this->pressed;
}

uint32 Button pressDuration(uint32 now)
{
  return this->pressed ? (now - this->lastPressedAt) : 0;
}

bool Button::wasReleasedThisFrame()
{
  return this->releasedThisFrame;
}

bool Button::wasPressed()
{
  return this->releasedThisFrame && this->lastPress = PRESS;
}

bool Button::wasLongPressed()
{
  return this->releasedThisFrame && this->lastPress = LONG_PRESS;
}
