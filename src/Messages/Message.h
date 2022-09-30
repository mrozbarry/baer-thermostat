#include "../Util/State/State.h"

#ifndef MESSAGES_MESSAGE_H
#define MESSAGES_MESSAGE_H 1

class Page;

class Message
{
public:
  Message();
  virtual bool shouldDispatch(State *state);
  virtual void execute(Page *page);
};

#endif

