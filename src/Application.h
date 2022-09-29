#ifndef APPLICATION_H
#define APPLICATION_H 1

#include "./Pages/Page.h"
#include "./Utils/State.h"

class Application
  : public Page
  , public State
{
public:
  Application();
  ~Application();

  void onTick(unsigned long now);

  State state;
}

#endif
