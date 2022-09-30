#include "./Home.h"

Home::Home(Page *root)
  : Page(root)
{}

void Home::tick(State *state)
{}

void Home::render(State *state)
{
  state->lcd.write("This is the home page", 0, 0);
}
