# serialpuny
Puny sized Attiny BitBanged Uart Library

Functions:

puny_show_speed() – Set baud rate.

puny_wakeup() – Initialize UART.

puny_throw() – Send byte.

puny_got() – Receive byte.

puny_sentence() – Send string.

puny_numbers() – Send number.


MCU | Tx Pin (PB1) | Rx Pin (PB3)
ATmega328P | Pin 9 | Pin 8
ATmega32 | Pin 9 | Pin 11
ATmega128 | Pin 9 | Pin 11
ATtiny85 | Pin 1 | Pin 3
ATtiny84 | Pin 15 | Pin 17
ATmega2560 | Pin 22 | Pin 23
ATmega8 | Pin 9 | Pin 10
ATmega168 | Pin 9 | Pin 8
ATmega32U4 | Pin 6 | Pin 7
ATmega1280 | Pin 22 | Pin 23
