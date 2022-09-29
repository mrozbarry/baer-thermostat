#include "./Application.h"

Application::Application()
  : state()
{}

Application::~Application()
{}

void Application::onTick(unsigned long now)
{
  this->state->update(now);
  this->render(&this->state);
}
