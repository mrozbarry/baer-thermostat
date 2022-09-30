#include "./ChangePage.h"
#include <iostream>

ChangePage::ChangePage(Page *nextPage, unsigned long changeAt)
{
  this->nextPage = nextPage;
  this->changeAt = changeAt;
}

bool ChangePage::shouldDispatch(State *state)
{
  bool willDispatch = state->now >= changeAt;
  return willDispatch;
}

void ChangePage::execute(Page *page)
{
  std::cout << "ChangePage::execute" << std::endl;
  page->stack(this->nextPage);
}
