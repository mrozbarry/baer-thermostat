#include "./Page.h"

Page::Page(Page *root)
  : child((Page *)0)
{
  this->root = root;
}

Page::~Page()
{
  if (this->child) {
    delete this->child;
  }
}

Page *Page::stack(Page *other)
{
  if (!this->child) {
    this->child = other;
    return this->child;
  }

  return this->child->stack(other);
}

void Page::onTick(State *state)
{
  if (this->child) {
    this->child->onTick(state);

    return;
  }

  this->tick(state);
  this->render(state);

  return;
}

void Page::onRender(State *state)
{
  if (this->child) {
    return this->child->onRender(state);
  }
  return this->render(state);
}

bool Page::dispatchMessage(Message *message)
{
  return this->root->dispatchMessage(message);
}

void Page::tick(State *state) {}
void Page::render(State *state) {}
