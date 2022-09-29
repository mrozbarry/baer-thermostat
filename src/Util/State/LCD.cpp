#include "./LCD.h"
#include <iostream>

LCD::LCD()
{
  // Custom characters
}

bool LCD::isTurnedOn()
{
  return false; // Not sure how you're checking this...
}

void LCD::write(const char *text, int row, int col)
{
  // TODO: do other stuff
  std::cout << text << std::endl;
}
