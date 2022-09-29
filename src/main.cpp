#include "./Application.h"

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
  atexit(cleanup);
}

void loop()
{
  if (!app) {
    return;
  }

  app->onTick(millis());
}
