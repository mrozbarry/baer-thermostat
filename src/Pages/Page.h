#include "../Util/State/State.h"
#include "../Messages/Message.h"

#ifndef PAGES_PAGE_H
#define PAGES_PAGE_H  1

class Page {
public:
  Page(Page *root);
  ~Page();

  Page *stack(Page *other);

  void render(State *state);
  void dispatchMessage(Message *message);
  void onMessage(Message *message);

protected:
  Page *root;
  Page *child;
}

#endif
