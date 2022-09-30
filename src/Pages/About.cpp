#include "./About.h"

About::About(Page *root)
  : Page(root)
{}

void About::tick(State *state)
{
}

void About::render(State *state)
{
  state->lcd.write("Baer Thermostat", 0, 0);
}
