# serialpuny
Puny sized  BitBanged Uart Library

Functions:

puny_show_speed() – Set baud rate.

puny_wakeup() – Initialize UART.

puny_throw() – Send byte.

puny_got() – Receive byte.

puny_sentence() – Send string.

puny_numbers() – Send number.


Here’s a quick list of common AVR-based MCUs and their corresponding Tx and Rx pins (PB1 and PB3) for UART communication, which can be used with the Puny Library.


Microcontroller	Tx Pin (PB1)	Rx Pin (PB3)


ATmega328P	PB1 (Pin 9)	PB3 (Pin 8)


ATmega32	PB1 (Pin 9)	PB3 (Pin 11)

ATmega128	PB1 (Pin 9)	PB3 (Pin 11)

ATtiny85	PB1 (Pin 1)	PB3 (Pin 3)

ATtiny84	PB1 (Pin 15)	PB3 (Pin 17)

ATmega2560	PB1 (Pin 22)	PB3 (Pin 23)

ATmega8	PB1 (Pin 9)	PB3 (Pin 10)

ATmega168	PB1 (Pin 9)	PB3 (Pin 8)

ATmega32U4	PB1 (Pin 6)	PB3 (Pin 7)

ATmega1280	PB1 (Pin 22)	PB3 (Pin 23)

