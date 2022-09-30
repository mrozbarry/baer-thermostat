#include "./Pages/Page.h"
#include "./Util/State/State.h"
#include "./Messages/Message.h"

#ifndef APPLICATION_H
#define APPLICATION_H 1

#define APPLICATION_QUEUED_MESSAGE_SIZE 5

class Application
  : public Page
{
public:
  Application();
  ~Application();

  void onTick(unsigned long now);
  void tick(State *state);
  void render(State *state);
  bool dispatchMessage(Message *message);
  void onMessage(Message *message);

private:

  Message **queuedMessage;
  State state;
};

#endif
