#include "./Application.h"
#include "./Pages/About.h"
#include "./Pages/Home.h"
#include "./Messages/ChangePage.h"
#include <iostream>

#ifndef NULL
#define NULL  0
#endif

Application::Application()
  : Page((Page *)0)
  , state()
{
  this->stack(new About(this));
  this->queuedMessage = new Message *[APPLICATION_QUEUED_MESSAGE_SIZE];
  for(unsigned short index = 0; index < APPLICATION_QUEUED_MESSAGE_SIZE; index++)
  {
    this->queuedMessage[index] = NULL;
  }
  this->dispatchMessage(new ChangePage(new Home((Page *)this), state.now + 3000));
}

Application::~Application()
{
  for(unsigned short index = 0; index < APPLICATION_QUEUED_MESSAGE_SIZE; index++)
  {
    if (!this->queuedMessage[index]) continue;
    delete this->queuedMessage[index];
    this->queuedMessage[index] = NULL;
  }
  delete this->queuedMessage;
}

void Application::onTick(unsigned long now)
{
  this->state.tick(now);
  std::cout << "Application::onTick now=" << this->state.now << std::endl;
  this->tick(&state);
  this->onRender(&state);
}

void Application::tick(State *state)
{
  for(unsigned short index = 0; index < APPLICATION_QUEUED_MESSAGE_SIZE; index++)
  {
    if (this->queuedMessage[index] == NULL) continue;

    if (this->queuedMessage[index]->shouldDispatch(state)) {
      std::cout << "Application::tick shouldDispatch ok" << std::endl;
      this->onMessage(this->queuedMessage[index]);
      delete this->queuedMessage[index];
      this->queuedMessage[index] = NULL;
    }
  }
}

void Application::render(State *state)
{}

bool Application::dispatchMessage(Message *message)
{
  for(unsigned short index = 0; index < APPLICATION_QUEUED_MESSAGE_SIZE; index++)
  {
    if (this->queuedMessage[index]) continue;

    this->queuedMessage[index] = message;
    std::cout << "Application::dispatchMessage ok" << std::endl;

    return true;
  }
  std::cout << "Application::dispatchMessage failed" << std::endl;
  return false;
}

void Application::onMessage(Message *message)
{
  message->execute(this);
}
