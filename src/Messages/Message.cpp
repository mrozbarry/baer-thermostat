#include "./Message.h"

Message::Message()
{}

bool Message::shouldDispatch(State *state)
{
  return true;
}

void Message::execute(Page *page)
{}
