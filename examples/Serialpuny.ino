#include <puny.h>

void setup() {
  puny_wakeup();
  puny_show_speed(9600);

  puny_sentence("Hello from PunyUART!\r\n");
  puny_numbers(12345);
  puny_sentence("\r\n");
}

void loop() {
  uint8_t c = puny_got(); // Wait for a character
  puny_throw(c);          // Send it back
}
