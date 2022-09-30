#include "./Application.h"
#include <chrono>

auto start = std::chrono::steady_clock::now();
Application *app;

void cleanup()
{
  if (app) {
    delete app;
  }
}

void setup()
{
  app = new Application();
  // atexit(cleanup);
}

void loop()
{
  if (!app) {
    return;
  }

  auto current = std::chrono::steady_clock::now();
  unsigned long millis = std::chrono::duration_cast<std::chrono::milliseconds>(current - start).count();
  app->onTick(millis);
}
