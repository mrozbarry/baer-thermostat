#include "../Util/State/State.h"
#include "../Messages/Message.h"

#ifndef PAGES_PAGE_H
#define PAGES_PAGE_H  1

class Page {
public:
  Page(Page *root);
  ~Page();

  Page *stack(Page *other);

  void onTick(State *state);
  void onRender(State *state);

  virtual void tick(State *state);
  virtual void render(State *state);

  bool dispatchMessage(Message *message);

protected:
  Page *root;
  Page *child;
};

#endif
