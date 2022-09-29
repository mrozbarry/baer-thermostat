#include "./Application.h"

Application::Application()
  : state()
{}

Application::~Application()
{}

void Application::onTick(uint32 now)
{
  this->state->update(now);
  this->render(&this->state);
}
