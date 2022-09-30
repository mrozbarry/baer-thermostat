#include "./OS.h"

void sleep(unsigned long milliseconds)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
