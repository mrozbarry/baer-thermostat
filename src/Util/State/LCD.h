#ifndef UTILS_STATE_LCD_H
#define UTILS_STATE_LCD_H 1

class LCD
{
public:
  LCD();

  bool isTurnedOn();
  void turnOn();

  void write(const char *text, int row, int col);
};

#endif
