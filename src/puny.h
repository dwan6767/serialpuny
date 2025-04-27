#ifndef PUNY_H
#define PUNY_H

#include <avr/io.h>

#include <stdlib.h>
#ifndef F_CPU
#define F_CPU 8000000UL 
#endif


#define Rx_DDR DDRB
#define Tx_DDR DDRB
#define Tx_PORT PORTB
#define Rx_STATE PINB
#define Rx_BIT PB1
#define Tx_BIT PB3

extern uint16_t Baud; 

#ifdef __cplusplus
extern "C" {
#endif
// Function declarations
void puny_wakeup(void);
void puny_throw(uint8_t data);
uint8_t puny_got(void);
void puny_show_speed(uint32_t rate);
void puny_sentence(const char *str);
void puny_numbers(int number);
void delay_us(uint16_t us);


#ifdef __cplusplus
}
#endif
#endif // PUNY_H

