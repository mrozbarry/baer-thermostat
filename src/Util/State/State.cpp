#include "./State.h"

State::State()
  : now(0)
  , outdoorTemp(1) // replace 1 with GPIO pin for the outdoor sensor
  , indoorTemp(2) // replace 2 with GPIO pin for the indoor sensor
  . lcd()
{}

void State::onTick(unsigned long now)
{
  this->now = now;

  this->buttons->up->onTick(this->now);
  this->buttons->down->onTick(this->now);
  this->buttons->left->onTick(this->now);
  this->buttons->right->onTick(this->now);
  this->buttons->select->onTick(this->now);
}
