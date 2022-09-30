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

void LCD::turnOn()
{
  // TODO
}

void LCD::write(const char *text, int row, int col)
{
  std::cout << "[LCD{" << row << ',' << col << "}] " << text << std::endl;
}
