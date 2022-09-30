#include "./Page.h"

#ifndef PAGES_ABOUT_H
#define PAGES_ABOUT_H 1

class About
  : public Page
{
public:
  About(Page *root);

  void tick(State *state);
  void render(State *state);
};

#endif
