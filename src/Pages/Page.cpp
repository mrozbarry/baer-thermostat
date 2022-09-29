#include "./Page.h"

Page::Page(Page *root)
  : child(null)
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
  if (!other->state) {
    other->state = this->state;
  }

  if (!this->child) {
    this->child = other;
    return this->child;
  }

  return this->child->stack(other);
}

void Page::render(State *state)
{
  if (this->child) {
    return this->child->render(state);
  }
}

void Page::onMessage(Message *message)
{
  if (this->child) {
    return this->child->onMessage(message);
  }
}
