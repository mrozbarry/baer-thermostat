#include "./Page.h"

#ifndef PAGES_HOME_H
#define PAGES_HOME_H  1

class Home
  : public Page
{
public:
  Home(Page *root);

  void tick(State *state);
  void render(State *state);
};

#endif
