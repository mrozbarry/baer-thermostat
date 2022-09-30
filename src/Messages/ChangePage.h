#include "./Message.h"
#include "../Pages/Page.h"

#ifndef MESSAGES_CHANGE_PAGE_H
#define MESSAGES_CHANGE_PAGE_H  1

class ChangePage
  : public Message
{
public:
  ChangePage(Page *nextPage, unsigned long changeAt);

  bool shouldDispatch(State *state);
  void execute(Page *page);

private:
  Page *nextPage;
  unsigned long changeAt;
};

#endif
