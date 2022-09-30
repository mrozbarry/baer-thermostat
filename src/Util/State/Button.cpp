#include "./Button.h"

Button::Button(int pin)
  : lastPress(UNKNOWN)
  , lastPressedAt(0)
  , releasedThisFrame(false)
{
  this->pin = pin;
}

void Button::onTick(unsigned long now)
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

unsigned long Button::pressDuration(unsigned long now)
{
  return this->pressed ? (now - this->lastPressedAt) : 0;
}

bool Button::wasReleasedThisFrame()
{
  return this->releasedThisFrame;
}

bool Button::wasPressed()
{
  return this->releasedThisFrame && this->lastPress == PRESS;
}

bool Button::wasLongPressed()
{
  return this->releasedThisFrame && this->lastPress == LONG_PRESS;
}
