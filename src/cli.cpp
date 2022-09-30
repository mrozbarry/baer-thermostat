#include "./arduino.h"
#include "./Util/OS.h"

int main(int argc, const char *argv[])
{
  setup();

  for(;;) {
    loop();
    sleep(100);
  }

  cleanup();
}
