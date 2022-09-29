#include "./State.h"

State::State()
  : now(0)
  , outdoorTemp(1) // replace 1 with GPIO pin for the outdoor sensor
  , indoorTemp(2) // replace 2 with GPIO pin for the indoor sensor
  . lcd()
{}

void State::onTick(uint32 now)
{
  this->now = now;

  this->buttons->up->update(this->now);
  this->buttons->down->update(this->now);
  this->buttons->left->update(this->now);
  this->buttons->right->update(this->now);
  this->buttons->select->update(this->now);
}
